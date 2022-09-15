/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:50:50 by coder             #+#    #+#             */
/*   Updated: 2022/09/14 23:45:32 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push	ps;

	validate(argc, argv);
	allocate(&ps, argc, argv);
	sort(&ps);
	clear_stack(&ps);
}
