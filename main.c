/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:58:38 by mcamaren          #+#    #+#             */
/*   Updated: 2025/07/29 18:58:40 by mcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_table	*table;
	int		i;

	i = 0;
	if (check_argument(argc, argv) == 0)
		return (1);
	table = ft_init_all(argv);
	set_philos(table);
	ft_free_philo(&table);
	return (0);
}
