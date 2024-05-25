/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:33:29 by nhimad            #+#    #+#             */
/*   Updated: 2024/05/25 11:38:43 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num_list	*f_node(t_num_list *node)
{
	while (node)
	{
		if (!node->previous->next)
			return (node);
		node = node->previous;
	}
	return (0);
}

void	ft_fix(t_num_list **list, int l)
{
	t_num_list	*fix;
	int			i;

	i = -1;
	fix = list[0];
	while (fix->next)
	{
		fix = fix->previous;
		i++;
	}
	while (i > 0 && i <= (l / 2))
	{
		re_rotate(list);
		i--;
	}
	while (i > 0 && i > (l / 2) && list[0]->next)
		rotate(list);
	if (!list[0]->next)
	{
		list[0]->previous->next = list[0];
		ft_putendl_fd("ra", 1);
		list[0] = f_node(list[0]);
	}
}
