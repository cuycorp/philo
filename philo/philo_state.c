/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:57:33 by mcamaren          #+#    #+#             */
/*   Updated: 2025/07/29 18:57:36 by mcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->routine);
	if (philo->table->stop_routine == 1)
	{
		pthread_mutex_unlock(&philo->table->routine);
		return ;
	}
	pthread_mutex_unlock(&philo->table->routine);
	philo_log(philo, THINK);
	if (philo->table->n_philos % 2 == 0)
		precise_usleep_interruptible((philo->table->time_to_eat
				- philo->table->time_to_sleep) * 990, philo->table);
	else
		precise_usleep_interruptible(((philo->table->time_to_eat) * 2
				- philo->table->time_to_sleep) * 990, philo->table);
}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->routine);
	if (philo->table->stop_routine == 1)
	{
		pthread_mutex_unlock(&philo->table->routine);
		return ;
	}
	pthread_mutex_unlock(&philo->table->routine);
	philo_log(philo, SLEEP);
	precise_usleep_interruptible(philo->table->time_to_sleep * 1000,
		philo->table);
}

void	philo_eat(t_philo *philo)
{
	if (simulation_finished(philo->table))
		return ;
	pthread_mutex_lock(&philo->table->last_meal_time);
	philo->last_meal_time = get_current_time(philo->table);
	pthread_mutex_unlock(&philo->table->last_meal_time);
	philo_log(philo, EAT);
	precise_usleep_interruptible(philo->table->time_to_eat * 1000,
		philo->table);
	if (simulation_finished(philo->table))
		return ;
	pthread_mutex_lock(&philo->table->num_meal);
	philo->nb_meal++;
	pthread_mutex_unlock(&philo->table->num_meal);
}

void	philo_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->routine);
	if (philo->table->stop_routine == 1)
	{
		pthread_mutex_unlock(&philo->table->routine);
		return ;
	}
	pthread_mutex_unlock(&philo->table->routine);
	philo_log(philo, FORK);
}

/*
void	philo_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	ft_putstr_fd("\033[1;31m", 1);
	ft_putnbr_fd(get_current_time(philo->table), 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo->id, 1);
	ft_putstr_fd(" died\n\n", 1);
	pthread_mutex_unlock(&philo->table->print);
}
*/

int	philo_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->routine);
	if (philo->table->stop_routine == 0)
	{
		philo_log(philo, DEAD);
		philo->table->stop_routine = 1;
	}
	pthread_mutex_unlock(&philo->table->routine);
	return (1);
}
