// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   sort.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/07/11 07:32:58 by coder             #+#    #+#             */
// /*   Updated: 2022/09/06 20:36:09 by rsiqueir         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../pushswap.h"

static void order_three(t_push *ps)
{
	int i[3];
	
	i[0] = ps->stack_a[0].content;
	i[1] = ps->stack_a[1].content;
	i[2] = ps->stack_a[2].content;
	if (i[0] < i[1] && i[1] < i[2])
		return ;
	if (i[0] < i[1] && i[1] > i[2] && i[0] < i[2])
	{
		rra(ps);
		sa(ps);
	}
	else if (i[0] > i[1] && i[1] < i[2] && i[0] < i[2])
		sa(ps);
	else if (i[0] > i[1] && i[1] > i[2])
	{
		sa(ps);
		rra(ps);
	}
	else if (i[0] > i[1] && i[1] < i[2] && i[0] > i[2])
	{
		rra(ps);
		rra(ps);
	}
	else
		rra(ps);
}

static void	order_four(t_push *stacks)
{
    int     i;
	int		min;
	t_stack	*stack;

    i = -1;
    stack = stacks->stack_a;
    min = find_min_number(stacks->stack_a, stacks->stack_size_a);
	while (++i < stacks->stack_size_a)
	{
		if (stack[0].content == min)
		{
			pb(stacks);
			break ;
		}
        ra(stacks);
	}
	order_three(stacks);
	pa(stacks);
}

static int	is_not_sorted(t_push *ps)
{
    int     i;
    int     size;

    i = -1;
    size = ps->stack_size_a - 1;
	while (++i < size)
	{
		if (ps->stack_a[i].content > ps->stack_a[i + 1].content)
			return (1);
	}
	return (0);
}

void sort(t_push *ps)
{
	if (is_not_sorted(ps))
	{
		if (ps->stack_size_a == 2 &&
			ps->stack_a[0].content > ps->stack_a[1].content)
				sa(ps);
		else if (ps->stack_size_a == 3)
			order_three(ps);
		else if (ps->stack_size_a == 4)
			order_four(ps);
		else
			radix_sort(ps);
	}
}
