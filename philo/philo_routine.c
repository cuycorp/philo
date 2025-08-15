/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:58:00 by mcamaren          #+#    #+#             */
/*   Updated: 2025/07/29 18:58:02 by mcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	delay_odd_philo(t_philo *philo)
{
	int	nb_meal;

	pthread_mutex_lock(&philo->table->num_meal);
	nb_meal = philo->nb_meal;
	pthread_mutex_unlock(&philo->table->num_meal);
	if (nb_meal > 0)
		return ;
	if (philo->id % 2 == 0)
		precise_usleep_interruptible(philo->table->time_to_eat * 1000, philo->table);
}

static void take_fork_and_eat(t_philo *philo, int fork, int next_fork)
{
	pthread_mutex_lock(&philo->table->philo[fork].fork);
	philo_fork(philo);
	pthread_mutex_lock(&philo->table->philo[next_fork].fork);
	philo_fork(philo);
	philo_eat(philo);
	pthread_mutex_unlock(&philo->table->philo[next_fork].fork);
	pthread_mutex_unlock(&philo->table->philo[fork].fork);
}

static void	start_dining(t_philo *philo)
{
	while (1)
	{
		if ((philo->id + 1) % philo->table->n_philos == 0)
			take_fork_and_eat(philo, 0, philo->id);
		else
			take_fork_and_eat(philo, philo->id, philo->id + 1);
		philo_sleep(philo);
		philo_think(philo);
		pthread_mutex_lock(&philo->table->routine);
		if (philo->table->stop_routine == 1)
		{
			pthread_mutex_unlock(&philo->table->routine);
			break ;
		}
		pthread_mutex_unlock(&philo->table->routine);
	}
}

void	*philo_routine(void *input)
{
	t_philo	*philo;

	philo = (t_philo *)input;
	delay_odd_philo(philo);
	start_dining(philo);
	return (NULL);
}
