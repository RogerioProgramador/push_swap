/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:52:02 by coder             #+#    #+#             */
/*   Updated: 2022/09/03 20:52:09 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_stack
{
	struct s_stack	*next;
	int				content;
	size_t			normalized_content;
}				t_stack;

typedef struct s_push
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		first;
	int		stack_size;
}			t_push;

/* allocate */
void	allocate(t_push *ps, int size, char **values);

/* operations */
void sa(t_push *ps);
void pa(t_push *ps);
void pb(t_push *ps);
void ra(t_push *ps);
void rra(t_push *ps);

/* sorting */
void	sort(t_push *ps);
void	radix_sort(t_push *push);

/* validate args */
void	validate(int argc, char *argv[]);
int		has_digit(char *argv[]);
int		has_duplicate(char *argv[]);
void	handle_error(int i);

/* libft */
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

/* stack functions */
int	ft_stacksize(t_stack *lst);
t_stack	*ft_stack_new(int content);
t_stack	*ft_stacklast(t_stack *lst);
void	ft_stack_add_back(t_stack **lst, t_stack *new);

#endif
