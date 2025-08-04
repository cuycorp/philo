/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:51:43 by mcamaren          #+#    #+#             */
/*   Updated: 2025/07/29 18:51:45 by mcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_alloc_struct(size_t size)
{
	void	*data;

	if (!size)
	{
		errno = EINVAL;
		perror("Invalid size: cannot allocate memory with size 0.");
		return (NULL);
	}
	data = malloc(size);
	if (!data)
	{
		perror("malloc failed");
		return (NULL);
	}
	ft_memset(data, 0, size);
	return (data);
}

long long	ft_atoi(const char *nptr)
{
	char		*cptr;
	long long	n;
	long long	sign;

	sign = 1;
	n = 0;
	cptr = (char *)nptr;
	while ((*cptr >= 9 && *cptr <= 13) || *cptr == 32)
		cptr++;
	if (*cptr == '-' || *cptr == '+')
	{
		if (*cptr == '-')
			sign *= -1;
		cptr++;
	}
	while (*cptr >= '0' && *cptr <= '9')
	{
		n = n * 10 + (*cptr - 48);
		cptr++;
	}
	return (sign * n);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

