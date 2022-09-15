/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:55:02 by coder             #+#    #+#             */
/*   Updated: 2022/09/14 23:45:32 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		write(1, s++, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

long	ft_atol(const char *str)
{
	long	res;
	long	sign;
	long	i;

	res = 0;
	sign = 1;
	i = 0;
	while ((*str == '\t') || (*str == '\v') || (*str == '\f') || (*str == '\r')
		|| (*str == ' ') || (*str == '\n'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && str[i] >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * sign);
}
