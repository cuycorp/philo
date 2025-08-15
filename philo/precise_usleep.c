/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precise_usleep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:08:13 by mcamaren          #+#    #+#             */
/*   Updated: 2025/07/29 20:08:16 by mcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	precise_usleep_interruptible(long usec, t_table *table)
{
	struct timeval	start;
	struct timeval	current;
	long			elapsed;
	long			chunk;

	chunk = 1000;
	gettimeofday(&start, NULL);
	while (1)
	{
		pthread_mutex_lock(&table->routine);
		if (table->stop_routine == 1)
		{
			pthread_mutex_unlock(&table->routine);
			return ;
		}
		pthread_mutex_unlock(&table->routine);
		usleep(chunk);
		gettimeofday(&current, NULL);
		elapsed = (current.tv_sec - start.tv_sec) * 1000000L + (current.tv_usec
				- start.tv_usec);
		if (elapsed >= usec)
			break ;
	}
}
