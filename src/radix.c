/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 05:50:17 by coder             #+#    #+#             */
/*   Updated: 2022/09/14 22:38:30 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

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

void	normalize_content(t_push *stacks)
{
	size_t	i;
	int		min;
	t_stack	*stack;

	i = -1;
	stack = stacks->stack_a;
	min = find_min_number(stacks->stack_a, stacks->stack_size_a);
	if (min < 0)
		min = min * -1;
	while (++i < stacks->stack_size_a)
		stack[i].normalized_content = stack[i].content + min;
}

void	radix_sort(t_push *stacks)
{
	size_t	i;
	int		j;
	int		size;
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
