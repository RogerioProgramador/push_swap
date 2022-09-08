/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:20:04 by coder             #+#    #+#             */
/*   Updated: 2022/09/08 08:14:24 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static char	*ft_strcpy(char *dest, char *src)
{
	char	*dest2;

	dest2 = dest;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	dest = dest2;
	return (dest);
}

char	*ft_strdup(char *s1)
{
	char	*dest;

	dest = malloc(ft_strlen(s1) + 1);
	if (!(dest))
		return (NULL);
	if (dest == 0)
		return (0);
	ft_strcpy(dest, s1);
	return (dest);
}


static void	*ft_memmove(void *dst, void *src, size_t len)
{
	size_t	i;
	void	*src_dup;

	if (dst == NULL && src == NULL)
		return (NULL);
	src_dup = ft_strdup(src);
	if (dst > src)
	{
		while (len-- > 0)
			((char *)dst)[len] = ((char *)src_dup)[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src_dup)[i];
			i++;
		}
	}
	return (dst);
}

static void	ft_swap(t_stack *a, t_stack *b)
{
	t_stack tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// void rra(t_push *ps)
// {
// 	t_stack *tmp1;
// 	t_stack *tmp2;
	
// 	tmp1 = ps->stack_a;
// 	while (tmp1->next->next != NULL)
// 		tmp1 = tmp1->next;
// 	tmp2 = tmp1->next;
// 	tmp1->next = NULL;
// 	tmp2->next = ps->stack_a;
// 	ps->stack_a = tmp2;
// 	ft_putstr("rra\n");
// }

void ra(t_push *ps)
{
	t_stack tmp;
	
	if (ps->stack_size_a == 1)
		return ;
	tmp = ps->stack_a[ps->stack_size_a - 1];
	ft_memmove(ps->stack_a + 1, ps->stack_a, ps->stack_size_a - 1);
	ps->stack_a[0] = tmp;
	ft_putstr("ra\n");
}

void sa(t_push *ps)
{
	if (ps->stack_size_a == 1)
		return ;
	ft_swap(&ps->stack_a[0], &ps->stack_a[1]);
	ft_putstr("sa\n");
}

void pa(t_push *ps)
{
	if (ps->stack_size_b == 0)
		return ;
	ft_memmove(ps->stack_a + 1, ps->stack_a, ps->stack_size_a);
	ps->stack_a[0] = ps->stack_b[0];
	ft_memmove(ps->stack_b, ps->stack_b + 1, ps->stack_size_b);
	ps->stack_size_a += 1;
	ps->stack_size_b -= 1;
	ft_putstr("pa\n");
}

void pb(t_push *ps)
{
	if (ps->stack_size_a == 0)
		return ;
	ft_memmove(ps->stack_b + 1, ps->stack_b, ps->stack_size_b);
	ps->stack_b[0] = ps->stack_a[0];
	ft_memmove(ps->stack_a, ps->stack_a + 1, ps->stack_size_a);
	ps->stack_size_b += 1;
	ps->stack_size_a -= 1;
	ft_putstr("pb\n");
}
