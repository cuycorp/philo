/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:00:17 by mcamaren          #+#    #+#             */
/*   Updated: 2025/07/29 19:00:19 by mcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


/*
-> Initializes table with the settings of the simulation
-> Initializes the mutex variables that are like the vitality 
   signs of the simulation
*/
static t_table	*init_table(char **argv)
{
	t_table	*table;

	table = ft_alloc_struct(sizeof(t_table));
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->time_to_die = ft_atoi(argv[2]);
	if (argv[5] == NULL)
		table->max_meal = -1;
	else
		table->max_meal = ft_atoi(argv[5]);
	table->stop_routine = 0;
	table->n_philos = ft_atoi(argv[1]);
	pthread_mutex_init(&table->print, NULL);
	pthread_mutex_init(&table->time, NULL);
	pthread_mutex_init(&table->routine, NULL);
	pthread_mutex_init(&table->num_meal, NULL);
	pthread_mutex_init(&table->last_meal_time, NULL);
	return (table);
}

/*
-> Resets the count variables
-> Initializes fork mutex
*/
static t_philo	*init_philo(t_table *table)
{
	t_philo	*philo;
	int		i;

	philo = ft_alloc_struct(sizeof(t_philo) * table->n_philos);
	i = 0;
	while (i < table->n_philos)
	{
		philo[i].id = i;
		philo[i].nb_meal = 0;
		philo[i].last_meal_time = 0;
		philo[i].table = table;
		pthread_mutex_init(&philo[i].fork, NULL);
		i++;
	}
	table->philo = philo;
	return (philo);
}


/*
-> Init table and philo 
-> Initialize gettimeofday
*/
t_table	*ft_init_all(char **argv)
{
	t_table *table;
	table = init_table(argv);
	init_philo(table);
	gettimeofday(&table->start_time, NULL);
	return (table);
}
