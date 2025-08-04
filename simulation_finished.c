/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_finished.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:27:40 by mcamaren          #+#    #+#             */
/*   Updated: 2025/07/29 15:27:43 by mcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	simulation_finished(t_table *table)
{
	pthread_mutex_lock(&table->routine);
	if (table->stop_routine == 1)
	{
		pthread_mutex_unlock(&table->routine);
		return (true);
	}
	pthread_mutex_unlock(&table->routine);
	return (false);
}
