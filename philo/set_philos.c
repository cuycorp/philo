/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:00:58 by mcamaren          #+#    #+#             */
/*   Updated: 2025/07/29 19:01:00 by mcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	one_philo(t_table *table)
{
	if (table->n_philos == 1)
	{
		philo_fork(table->philo);
		precise_usleep_interruptible(table->time_to_die * 1000, table);
		philo_dead(table->philo);
		return (1);
	}
	return (0);
}

void    set_philos(t_table *table)
{
    int i;
    i = 0;
    pthread_t monitor;

    if (one_philo(table) == 1)
		return ;
    pthread_create(&monitor, NULL, monitor_routine, (void *)table);
    while(i < table->n_philos)
    {
        pthread_create(&table->philo[i].thread, NULL, philo_routine, (void *)&table->philo[i]);
        i++;
    }
    i = 0;
    pthread_join(monitor, NULL);
    while(i < table->n_philos)
    {
        pthread_join(table->philo[i].thread, NULL);
        i++;
    }
	ft_putstr_fd("\033[0;37m", 1);
}
