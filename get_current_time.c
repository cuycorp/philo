/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:58:53 by mcamaren          #+#    #+#             */
/*   Updated: 2025/07/29 18:58:56 by mcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_current_time(t_table *table)
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return ((time.tv_sec - table->start_time.tv_sec) * 1000) + ((time.tv_usec
			- table->start_time.tv_usec) / 1000);
}
