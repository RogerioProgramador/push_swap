/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:20:04 by coder             #+#    #+#             */
/*   Updated: 2022/09/14 22:32:37 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ra(t_push *ps)
{
	t_stack	tmp;

	if (ps->stack_size_a < 1)
		return ;
	tmp = ps->stack_a[0];
	move_memmory_back(ps->stack_a, ps->stack_size_a);
	ps->stack_a[ps->stack_size_a - 1] = tmp;
	ft_putstr("ra\n");
}

void	rra(t_push *ps)
{
	t_stack	tmp;

	if (ps->stack_size_a < 1)
		return ;
	tmp = ps->stack_a[ps->stack_size_a - 1];
	move_memmory_foward(ps->stack_a, ps->stack_size_a);
	ps->stack_a[0] = tmp;
	ft_putstr("rra\n");
}

void	sa(t_push *ps)
{
	if (ps->stack_size_a == 1)
		return ;
	swap(&ps->stack_a[0], &ps->stack_a[1]);
	ft_putstr("sa\n");
}

void	pa(t_push *ps)
{
	if (ps->stack_size_b == 0)
		return ;
	move_memmory_foward(ps->stack_a, ps->stack_size_a);
	ps->stack_a[0] = ps->stack_b[0];
	ps->stack_size_a += 1;
	ps->stack_size_b -= 1;
	move_memmory_back(ps->stack_b, ps->stack_size_b);
	ft_putstr("pa\n");
}

void	pb(t_push *ps)
{
	if (ps->stack_size_a == 0)
		return ;
	move_memmory_foward(ps->stack_b, ps->stack_size_b);
	ps->stack_b[0] = ps->stack_a[0];
	ps->stack_size_b += 1;
	ps->stack_size_a -= 1;
	move_memmory_back(ps->stack_a, ps->stack_size_a);
	ft_putstr("pb\n");
}
