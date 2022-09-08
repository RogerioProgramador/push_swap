/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:50:50 by coder             #+#    #+#             */
/*   Updated: 2022/09/08 08:18:34 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../pushswap.h"

#include <stdio.h>
void test_stack(t_push *ps)
{
	int i = 0;

	printf("test stack a: ");
	
	while (i < ps->stack_size_a)
	{
		printf("%i ", ps->stack_a[i].content);
		i++;
	}
	printf("stack size a: %i \n", ps->stack_size_a);
	printf("\n");

	printf("test stack b: ");
	
	i = 0;
	while (i < ps->stack_size_b)
	{
		printf("%i ", ps->stack_b[i].content);
		i++;
	}
	printf("stack size b: %i \n", ps->stack_size_b);
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_push ps;
	
	validate(argc, argv);
	allocate(&ps, argc, argv);
	// sort(&ps);
	pa(&ps);
	pb(&ps);
	pb(&ps);
	// pb(&ps);
	// pb(&ps);
	// ra(&ps);
	test_stack(&ps);
	free(ps.stack_a);
	free(ps.stack_b);
}
