/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:59:43 by mcamaren          #+#    #+#             */
/*   Updated: 2025/07/29 18:59:45 by mcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	isnum(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

static int	is_all_numbers(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j])
		{
			if (isnum(argv[i][j]) != 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_range(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}
int	check_argument(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (write(2, "Error\nNot enough arguments\n", 27), 0);
	if (check_range(argv) == 0)
		return (write(2, "Error\nWrong time range\n", 23), 0);
	if (is_all_numbers(argv) == 0)
		return (write(2, "Error\nOnly number is accepted\n", 30), 0);
	write(1, "EVERYTHING IS GOOD\n", 19);
	return (1);
}
