/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:34:05 by nhimad            #+#    #+#             */
/*   Updated: 2024/05/25 11:38:48 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_num_list **list, t_num_list **b)
{
	t_num_list	*node;

	node = b[0];
	if (b[0]->next)
		b[0]->next->previous = b[0]->previous;
	b[0] = b[0]->next;
	node->next = list[0];
	node->previous = list[0]->previous;
	list[0]->previous = node;
	list[0] = node;
	if (list[0]->previous->next)
		list[0]->previous->next = list[0];
	ft_putendl_fd("pa", 1);
}

void	push_sort(t_num_list **list, t_num_list **b)
{
	while (b[0])
	{
		perfect_move(list, b);
		if (b[0]->number < list[0]->number)
		{
			while (list[0]->previous->next
				&& b[0]->number < list[0]->previous->number)
			{
				list[0] = list[0]->previous;
				ft_putendl_fd("rra", 1);
			}
			push_a(list, b);
		}
		else
		{
			while (list[0] && b[0]->number > list[0]->number)
			{
				list[0] = list[0]->next;
				ft_putendl_fd("ra", 1);
			}
			push_a(list, b);
		}
	}
}
