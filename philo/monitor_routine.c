/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:58:21 by mcamaren          #+#    #+#             */
/*   Updated: 2025/07/29 18:58:23 by mcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_meal(t_table *table)
{
	int	i;

	i = 0;
	if (table->max_meal == -1)
		return (0);
	while (i < table->n_philos)
	{
		pthread_mutex_lock(&table->num_meal);
		if (table->philo[i].nb_meal < table->max_meal)
			return (pthread_mutex_unlock(&table->num_meal), 0);
		pthread_mutex_unlock(&table->num_meal);
		i++;
	}
	return (1);
}

int	check_death(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->n_philos)
	{
		pthread_mutex_lock(&table->last_meal_time);
		if (table->time_to_die <= get_current_time(table)
			- table->philo[i].last_meal_time)
		{
			pthread_mutex_unlock(&table->last_meal_time);
			return (philo_dead(&table->philo[i]));
		}
		pthread_mutex_unlock(&table->last_meal_time);
	}
	return (0);
}

/*
static int	check_death(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		pthread_mutex_lock(&table->last_meal_time);
		if (table->time_to_die <= get_current_time(table)
			- table->philo[i].last_meal_time)
			return (pthread_mutex_unlock(&table->last_meal_time), usleep(500),
				philo_dead(&table->philo[i]), 1);
		pthread_mutex_unlock(&table->last_meal_time);
		i++;
	}
	return (0);
}
*/

void	*monitor_routine(void *input)
{
	t_table	*table;

	table = (t_table *)input;
	while (1)
	{
		if (check_meal(table) == 1 || check_death(table) == 1)
		{
			pthread_mutex_lock(&table->routine);
			table->stop_routine = 1;
			pthread_mutex_unlock(&table->routine);
			break ;
		}
		if (table->stop_routine == 1)
			break ;
		precise_usleep_interruptible(1000, table);
	}
	return (NULL);
}
