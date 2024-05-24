/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:24:16 by nhimad            #+#    #+#             */
/*   Updated: 2024/05/24 12:36:59 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	l_add_back(t_num_list **list, int n)
{
	t_num_list			*node;
	static t_num_list	*last;

	node = malloc(sizeof(t_num_list));
	if (!node)
		return (1);
	node->number = n;
	if (!list[0])
	{
		list[0] = node;
		node->next = NULL;
		node->previous = NULL;
		last = list[0];
	}
	else
	{
		last->next = node;
		node->previous = last;
		node->next = NULL;
		last = node;
	}
	list[0]->previous = last;
	return (0);
}
