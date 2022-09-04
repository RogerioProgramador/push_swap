/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:20:04 by coder             #+#    #+#             */
/*   Updated: 2022/07/11 06:54:50 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void rra(t_push *ps)
{
	t_stack *tmp1;
	t_stack *tmp2;
	
	tmp1 = ps->stack_a;
	while (tmp1->next->next != NULL)
		tmp1 = tmp1->next;
	tmp2 = tmp1->next;
	tmp1->next = NULL;
	tmp2->next = ps->stack_a;
	ps->stack_a = tmp2;
	ft_putstr("rra\n");
}

void ra(t_push *ps)
{
	t_stack *tmp;

	tmp = ps->stack_a;
	ps->stack_a = tmp->next;
	tmp->next = NULL;
	ft_stack_add_back(&(ps->stack_a), tmp);
	ft_putstr("ra\n");
}

void sa(t_push *ps)
{
	t_stack *tmp;

	if (!ps->stack_a->next)
		return ;
	tmp = ps->stack_a->next;
	ps->stack_a->next = tmp->next;
	tmp->next = ps->stack_a;
	ps->stack_a = tmp;
	ft_putstr("sa\n");
}

void pa(t_push *ps)
{
	t_stack *tmp;

	if (!ps->stack_b)
		return ;
	tmp = ps->stack_b;
	ps->stack_b = tmp->next;
	tmp->next = ps->stack_a;
	ps->stack_a = tmp;
	ft_putstr("pa\n");
}

void pb(t_push *ps)
{
	t_stack	*tmp;

	if (!ps->stack_a)
		return ;
	tmp = ps->stack_a;
	ps->stack_a = tmp->next;
	tmp->next = ps->stack_b;
	ps->stack_b = tmp;
	ft_putstr("pb\n");
}
