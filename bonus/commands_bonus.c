/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:33:34 by nhimad            #+#    #+#             */
/*   Updated: 2024/05/24 12:50:55 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	list_l(t_num_list *b)
{
	int	i;

	i = 0;
	while (b)
	{
		b = b->next;
		i++;
	}
	return (i);
}

void	swap(t_num_list **list)
{
	t_num_list	*temp;

	temp = 0;
	if (list_l(list[0]) > 1)
	{
		temp = list[0]->next;
		list[0]->next = temp->next;
		if (temp->next)
		{
			(temp->next)->previous = temp->previous;
			temp->previous = list[0]->previous;
			list[0]->previous = temp;
		}
		temp->next = list[0];
		list[0] = temp;
	}
}

void	rotate(t_num_list **list)
{
	if (list[0])
	{
		list[0]->previous->next = list[0];
		list[0] = list[0]->next;
		list[0]->previous->next = NULL;
	}
}

void	re_rotate(t_num_list **list)
{
	if (list[0])
	{
		list[0]->previous->next = list[0];
		list[0] = list[0]->previous;
		list[0]->previous->next = NULL;
	}
}
