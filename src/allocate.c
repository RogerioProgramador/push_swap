/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 07:15:14 by coder             #+#    #+#             */
/*   Updated: 2022/09/08 07:28:20 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h" 

static void init(int *size, int *i, t_push *ps)
{
	*i = 0;
	*size -= 1;
	ps->stack_size_a = *size;
	ps->stack_size_b = 0;
	ps->stack_b = (t_stack *)malloc(sizeof(t_stack) * (*size));
	ps->stack_a = (t_stack *)malloc(sizeof(t_stack) * (*size));
}

void allocate(t_push *ps, int size, char **values)
{
	int i;
	
	init(&size, &i, ps);
	while (++i <= size)
		ps->stack_a[i - 1].content = atoi(values[i]);
}
