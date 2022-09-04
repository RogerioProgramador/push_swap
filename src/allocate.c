/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 07:15:14 by coder             #+#    #+#             */
/*   Updated: 2022/09/03 21:21:03 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h" 

static void init(int *i, t_push *ps, char **value)
{
	*i = 2;
	ps->first = 0;
	ps->stack_size = 0;
	ps->stack_a = NULL;
	ps->stack_b = NULL;
	ps->stack_a = ft_stack_new(ft_atoi(*value));
}

void allocate(t_push *ps, int size, char **values)
{
	int i;
	
	init(&i, ps, &values[1]);
	while (i < size)
		ft_stack_add_back(&ps->stack_a, ft_stack_new(ft_atoi(values[i++])));
}
