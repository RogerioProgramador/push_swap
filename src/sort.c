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

// #include "../pushswap.h"

// static int find_min_number(t_stack *stack)
// {
// 	int	number;

// 	number = stack->content;
// 	while (stack)
// 	{
// 		if (stack->content < number)
// 			number = stack->content;
// 		stack = stack->next;
// 	}
// 	return (number);
// }

// static void order_three(t_push *ps)
// {
// 	int i[3];
	
// 	i[0] = ps->stack_a->content;
// 	i[1] = ps->stack_a->next->content;
// 	i[2] = ps->stack_a->next->next->content;
// 	if (i[0] < i[1] && i[1] < i[2])
// 		return ;
// 	if (i[0] < i[1] && i[1] > i[2] && i[0] < i[2])
// 	{
// 		rra(ps);
// 		sa(ps);
// 	}
// 	else if (i[0] > i[1] && i[1] < i[2] && i[0] < i[2])
// 		sa(ps);
// 	else if (i[0] > i[1] && i[1] > i[2])
// 	{
// 		sa(ps);
// 		rra(ps);
// 	}
// 	else if (i[0] > i[1] && i[1] < i[2] && i[0] > i[2])
// 	{
// 		rra(ps);
// 		rra(ps);
// 	}
// 	else
// 		rra(ps);
// }

// static void	order_four(t_push *stacks)
// {
// 	int		min;
// 	t_stack	*stack;

// 	stack = stacks->stack_a;
// 	min = find_min_number(stacks->stack_a);
// 	while (stack != NULL)
// 	{
// 		if (stack->content == min)
// 		{
// 			pb(stacks);
// 			break ;
// 		}
// 		stack = stack->next;
// 		ra(stacks);
// 	}
// 	order_three(stacks);
// 	pa(stacks);
// }

// static int	is_not_sorted(t_push *ps)
// {
// 	t_stack	*first;
// 	t_stack	*second;
	
// 	second = ps->stack_a;
// 	first = second;
// 	while (second->next)
// 	{
// 		second = second->next;
// 		if (first->content > second->content)
// 			return (1);
// 		first = first->next;
// 	}
// 	return (0);
// }

// void sort(t_push *ps)
// {
// 	if (is_not_sorted(ps))
// 	{
// 		ps->stack_size = ft_stacksize(ps->stack_a);
// 		if (ps->stack_size == 2 &&
// 			ps->stack_a->content > ps->stack_a->next->content)
// 				sa(ps);
// 		else if (ps->stack_size == 3)
// 			order_three(ps);
// 		else if (ps->stack_size == 4)
// 			order_four(ps);
// 		else
// 			radix_sort(ps);
// 	}
// }
