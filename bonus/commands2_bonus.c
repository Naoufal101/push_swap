/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:57:40 by nhimad            #+#    #+#             */
/*   Updated: 2024/05/24 12:51:04 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
}

void	push_b(t_num_list **list, t_num_list **b)
{
	t_num_list	*node;

	if (list[0])
	{
		node = list[0];
		if (list[0]->next)
			list[0]->next->previous = list[0]->previous;
		list[0] = list[0]->next;
		add_b(b, node);
	}
}

void	push_a(t_num_list **list, t_num_list **b)
{
	t_num_list	*node;

	if (b[0])
	{
		node = b[0];
		if (b[0]->next)
			b[0]->next->previous = b[0]->previous;
		b[0] = b[0]->next;
		node->next = list[0];
		if (list[0])
		{
			node->previous = list[0]->previous;
			list[0]->previous = node;
			list[0] = node;
			if (list[0]->previous->next)
				list[0]->previous->next = list[0];
		}
	}
}
