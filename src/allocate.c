/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 07:15:14 by coder             #+#    #+#             */
/*   Updated: 2022/09/14 23:45:32 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

static void	init(int *size, int *i, t_push *ps)
{
	*i = 0;
	*size -= 1;
	ps->stack_size_a = *size;
	ps->stack_size_b = 0;
	ps->stack_b = (t_stack *)malloc(sizeof(t_stack) * (ps->stack_size_a + 1));
	ps->stack_a = (t_stack *)malloc(sizeof(t_stack) * (ps->stack_size_a + 1));
}

void	allocate(t_push *ps, int size, char **values)
{
	int	i;

	init(&size, &i, ps);
	while (++i <= size)
		ps->stack_a[i - 1].content = ft_atol(values[i]);
}
