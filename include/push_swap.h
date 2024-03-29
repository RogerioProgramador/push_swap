/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:48:15 by rsiqueir          #+#    #+#             */
/*   Updated: 2022/09/14 23:48:35 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				content;
	size_t			normalized_content;
}	t_stack;

typedef struct s_push
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	size_t	stack_size_a;
	size_t	stack_size_b;
}	t_push;

void	allocate(t_push *ps, int size, char **values);

/* operations */
void	sa(t_push *ps);
void	pa(t_push *ps);
void	pb(t_push *ps);
void	ra(t_push *ps);
void	rra(t_push *ps);

/* sorting */
void	sort(t_push *ps);
void	radix_sort(t_push *push);

/* validate args */
void	validate(int argc, char *argv[]);

/* lib */
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s);
int		ft_isdigit(int c);
long	ft_atol(const char *str);

/* stack functions */
void	move_memmory_foward(t_stack *stack, size_t size);
void	move_memmory_back(t_stack *stack, size_t size);
int		find_min_number(t_stack *stack, size_t size);
void	swap(t_stack *a, t_stack *b);
void	clear_stack(t_push *ps);

#endif
