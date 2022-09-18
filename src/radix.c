/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 05:50:17 by coder             #+#    #+#             */
/*   Updated: 2022/09/16 20:54:55 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_bits(t_push *stacks)
{
	size_t	i;
	t_stack	*stack;
	size_t	max;
	size_t	max_bits;

	i = -1;
	max_bits = 0;
	stack = stacks->stack_a;
	max = stack[0].normalized_content;
	while (++i < stacks->stack_size_a)
	{
		if (stack[i].normalized_content > max)
			max = stack[i].normalized_content;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	selection_sort(t_stack *stack, int tam)
{
	int	i;
	int	j;
	int	min;
	int	aux;

	i = 0;
	while (i < (tam - 1))
	{
		min = i;
		j = i + 1;
		while (j < tam)
		{
			if (stack[j].content < stack[min].content)
				min = j;
			j++;
		}
		if (i != min)
		{
			aux = stack[i].content;
			stack[i].content = stack[min].content;
			stack[min].content = aux;
		}
		i++;
	}
}

static int	find_position(int pos, t_push *stacks)
{
	int		i;
	int		size;
	int		value;
	t_stack	*stack;

	i = 0;
	value = stacks->stack_a[pos].content;
	stack = stacks->stack_b;
	size = stacks->stack_size_a;
	while (i < size)
	{
		if (stack[i].content == value)
			return (i);
		i++;
	}
	return (0);
}

static void	normalize_content(t_push *stacks)
{
	t_stack	*stack;
	size_t	i;

	i = -1;
	stack = stacks->stack_a;
	selection_sort(stacks->stack_b, stacks->stack_size_a);
	while (++i < stacks->stack_size_a)
		stack[i].normalized_content = find_position(i, stacks);
}

void	radix_sort(t_push *stacks)
{
	size_t	i;
	size_t	j;
	size_t	size;
	size_t	bits;

	i = -1;
	size = stacks->stack_size_a;
	normalize_content(stacks);
	bits = get_bits(stacks);
	while (++i < bits)
	{
		j = -1;
		while (++j < size)
		{
			if (((stacks->stack_a[0].normalized_content >> i) & 1) == 1)
				ra(stacks);
			else
				pb(stacks);
		}
		while (stacks->stack_size_b != 0)
			pa(stacks);
	}
}
