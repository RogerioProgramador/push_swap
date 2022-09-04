/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:50:50 by coder             #+#    #+#             */
/*   Updated: 2022/09/03 21:01:58 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../pushswap.h"

/*JUST FOR TESTS*/
# include <stdio.h>
static void test_stack(t_push *ps)
{
	ft_putstr("stack: ");
	while (ps->stack_a)
	{
		printf("%i ", ps->stack_a->content);
		ps->stack_a = ps->stack_a->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_push ps;
	
	validate(argc, argv);
	allocate(&ps, argc, argv);
	write(1, "\n|erro|\n", 8);
	test_stack(&ps);
	sort(&ps);
}
