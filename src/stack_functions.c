/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 02:23:50 by coder             #+#    #+#             */
/*   Updated: 2022/09/12 21:32:27 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../pushswap.h"

void    move_memmory_foward(t_stack *stack, size_t size)
{
	if (size == 0)
		return ;
	while (size > 0)
	{
		stack[size] = stack[size - 1];
		size--;
	}
}

void	move_memmory_back(t_stack *stack, size_t size)
{
	int	i;

	i = 0;
	if (size == 0)
		return ;
	while (i < size)
	{
		stack[i] = stack[i + 1];
		i++;
	}
}

void	swap(t_stack *a, t_stack *b)
{
	t_stack tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int find_min_number(t_stack *stack, size_t size)
{
    int i;
	int	number;

    i = 0;
	number = stack[0].content;
	while (++i < size)
	{
		if (stack[i].content < number)
			number = stack[i].content;
	}
	return (number);
}

void clear_stack(t_push *ps)
{
	free(ps->stack_a);
	free(ps->stack_b);
}