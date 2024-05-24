/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:34:49 by nhimad            #+#    #+#             */
/*   Updated: 2024/05/19 19:37:40 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	add_b(t_num_list **b, t_num_list *node)
{
	if (!b[0])
	{
		b[0] = node;
		node->next = NULL;
		node->previous = node;
	}
	else
	{
		node->previous = b[0]->previous;
		b[0]->previous = node;
		node->next = b[0];
		b[0] = node;
	}
	ft_putendl_fd("pb", 1);
}

void	push_b(t_num_list **list, t_num_list **b)
{
	t_num_list	*node;

	node = list[0];
	list[0]->next->previous = list[0]->previous;
	list[0] = list[0]->next;
	add_b(b, node);
}
