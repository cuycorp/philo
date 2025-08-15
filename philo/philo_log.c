/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:24:18 by mcamaren          #+#    #+#             */
/*   Updated: 2025/07/29 20:24:22 by mcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    philo_log(t_philo *philo, t_philo_log log_type)
{
	pthread_mutex_lock(&philo->table->print);
	if (log_type == DEAD)
		ft_putstr_fd("\033[1;33m", 1);
	ft_putnbr_fd(get_current_time(philo->table), 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo->id, 1);
    if (log_type == FORK)
	    ft_putstr_fd(" has taken a fork\n\n", 1);
	else if (log_type == EAT)
	    ft_putstr_fd(" is eating\n\n", 1);
	else if (log_type == SLEEP)
	    ft_putstr_fd(" is sleeping\n\n", 1);
	else if (log_type == THINK)
	    ft_putstr_fd(" is thinking\n\n", 1);
	else if (log_type == DEAD)
		ft_putstr_fd(" died\n\n", 1);
	pthread_mutex_unlock(&philo->table->print);
}
