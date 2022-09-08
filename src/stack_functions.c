// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   stack_functions.c                                  :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/07/11 02:23:50 by coder             #+#    #+#             */
// /*   Updated: 2022/09/04 23:01:14 by rsiqueir         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// # include "../pushswap.h"

// int	ft_stacksize(t_stack *lst)
// {
// 	int	i;

// 	i = 0;
// 	while (lst)
// 	{
// 		lst = lst->next;
// 		i++;
// 	}
// 	return (i);
// }

// t_stack	*ft_stacklast(t_stack *lst)
// {
// 	if (!lst)
// 		return (NULL);
// 	while (lst -> next)
// 		lst = lst -> next;
// 	return (lst);
// }

// void	ft_stack_add_back(t_stack **lst, t_stack *new)
// {
// 	t_stack	*pointer;

// 	if (!*lst)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	pointer = ft_stacklast(*lst);
// 	pointer->next = new;
// }

// t_stack	*ft_stack_new(int content)
// {
// 	t_stack	*new;

// 	new = (t_stack *)malloc(sizeof(t_stack) * 1);
// 	if (!new)
// 		return (NULL);
// 	new -> content = content;
// 	new -> next = NULL;
// 	return (new);
// }