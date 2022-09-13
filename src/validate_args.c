/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:48:45 by coder             #+#    #+#             */
/*   Updated: 2022/09/12 21:23:15 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../pushswap.h"

static int has_duplicate(char *argv[], size_t size)
{	
	int	i[2];
	int	*pointer;

	i[0] = -1;
	pointer = (int *)malloc(size * sizeof(int));
	if (!pointer)
		return (1);
	while (++i[0] < size)
		pointer[i[0]] = ft_atoi(argv[i[0] + 1]);
	i[0] = -1;
	while (++i[0] < size)
	{
		i[1] = i[0];
		while (++i[1] < size)
		{
			if (pointer[i[0]] == pointer[i[1]])
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

static int has_digit(char *argv[])
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

static void	handle_error(int i)
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
	else if (has_duplicate(argv, argc - 1))
		handle_error(2);
}