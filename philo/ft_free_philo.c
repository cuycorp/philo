/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:59:25 by mcamaren          #+#    #+#             */
/*   Updated: 2025/07/29 18:59:27 by mcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	free_mutex(t_table **table)
{
	t_philo	*philo;
	int		i;

	philo = (*table)->philo;
	i = 0;
	while (i < (*table)->n_philos)
	{
		pthread_mutex_destroy(&philo[i].fork);
		i++;
	}
}

void	ft_free_philo(t_table **table)
{
	free_mutex(table);
	free((*table)->philo);
	pthread_mutex_destroy(&(*table)->print);
	pthread_mutex_destroy(&(*table)->time);
	pthread_mutex_destroy(&(*table)->routine);
	pthread_mutex_destroy(&(*table)->num_meal);
	pthread_mutex_destroy(&(*table)->last_meal_time);
	free(*table);
	*table = NULL;
}
