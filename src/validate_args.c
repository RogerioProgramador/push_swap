/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:48:45 by coder             #+#    #+#             */
/*   Updated: 2022/09/03 21:03:22 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../pushswap.h"

int has_duplicate(char *argv[])
{	
	int	i;
	int	j;
	int size;
	int	*pointer;

	i = 0;
	size = 0;
	while (argv[size])
		size++;
	pointer = (int *) malloc(size * sizeof(int));
	if (!pointer)
		return (1);
	while (argv[i])
	{
		pointer[i] = ft_atoi(argv[i]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (pointer[i] == pointer[j])
			{
				free(pointer);
				return (1);
			}
			j++;
		}
		i++;
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

int has_digit(char *argv[])
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (has_invalid_digits(argv[i]))
			return(1);
		i++;
	}
	return(0);
}

void	handle_error(int i)
{
	if (i == 0)
		ft_putstr("error: invalid arguments\n");
	else if (i == 1)
		ft_putstr("error: digit\n");
	else if (i == 2)
		ft_putstr("error: duplicate\n");
	exit(0);
}

void	validate(int argc, char *argv[])
{
	if (argc < 2 || !argv[1])
		handle_error(0);
	else if (has_digit(argv))
		handle_error(1);
	else if (has_duplicate(argv))
		handle_error(2);
}