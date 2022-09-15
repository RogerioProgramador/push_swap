/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:48:45 by coder             #+#    #+#             */
/*   Updated: 2022/09/14 22:37:52 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	bigger_than_int(long *number, size_t i[2])
{
	if (number[i[0]] > 2147483647 || number[i[0]] < -2147483648
		|| number[i[1]] > 2147483647 || number[i[1]] < -2147483648)
		return (1);
	return (0);
}

static int	has_duplicate(char *argv[], size_t size)
{	
	size_t	i[2];
	long	*pointer;

	i[0] = -1;
	pointer = (long *)malloc(size * sizeof(long));
	if (!pointer)
		return (1);
	while (++i[0] < size)
		pointer[i[0]] = ft_atol(argv[i[0] + 1]);
	i[0] = -1;
	while (++i[0] < size)
	{
		i[1] = i[0];
		while (++i[1] < size)
		{
			if (pointer[i[0]] == pointer[i[1]] || bigger_than_int(pointer, i))
			{
				free(pointer);
				return (1);
			}
		}
	}
	free(pointer);
	return (0);
}

static int	has_invalid_digits(char *arg)
{
	int	i;
	int	size;

	i = 1;
	if (arg[0] != '-' && !ft_isdigit(arg[0]))
		return (1);
	size = ft_strlen(arg);
	while (i < size)
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	has_digit(char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (has_invalid_digits(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

void	validate(int argc, char *argv[])
{
	if (argc < 2 || !argv[1])
		exit(0);
	if (has_digit(argv) || has_duplicate(argv, argc - 1))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}
