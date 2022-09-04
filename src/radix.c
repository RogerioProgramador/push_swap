/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 05:50:17 by coder             #+#    #+#             */
/*   Updated: 2022/08/27 03:02:46 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	get_bits(t_stack **stack)
{
	t_stack	*head;
	int		max;
	int		max_bits;

	head = (*stack);
	max = head->content;
	max_bits = 0;
	while (head)
	{
		if (head->content > max)
			max = head->content;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

int find_max(t_stack **stack)
{
	t_stack *head;
	int		max;

	head = (*stack);
	max = head->content;
	while (stack)
	{
		if (head->content > max)
			max = head->content;
		head = head->next;
	}
	return max;
}

int find_min(t_stack **stack)
{
	t_stack *head;
	int		min;

	head = (*stack);
	min = head->content;
	while (stack)
	{
		if (head->content < min)
			min = head->content;
		head = head->next;
	}
	return min;
}

void normalize_content(t_stack **stack)
{
	int		min;
	t_stack	*head;

	min = find_min(stack);
	head = *stack;

	if (min < 0)
		min = min * -1;
	while (head)
	{
		head->normalized_content = head->content + min;
		head = head->next;
	}	
}

void	radix_sort(t_push *stacks)
{
	int		i;
	int		j;
	int		size;
	t_stack	*stack;
	int		bits;

	i = -1;
	size = stacks->stack_size;
	stack = stacks->stack_a;
	normalize_content(&stacks->stack_a);
	bits = get_bits(&stack);
	while (++i < bits)
	{
		j = -1;
		while (++j < size)
		{
			stack = stacks->stack_a;
			if (((stack->normalized_content >> i) & 1) == 1)
				ra(stacks);
			else
				pb(stacks);
		}
		while (ft_stacksize(stacks->stack_b) != 0)
			pa(stacks);
	}
}

