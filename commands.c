/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:33:34 by nhimad            #+#    #+#             */
/*   Updated: 2024/05/25 11:38:34 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_num_list **list)
{
	t_num_list	*temp;

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
	ft_putendl_fd("sa", 1);
}

void	rotate(t_num_list **list)
{
	list[0]->previous->next = list[0];
	list[0] = list[0]->next;
	list[0]->previous->next = NULL;
	ft_putendl_fd("ra", 1);
}

void	re_rotate(t_num_list **list)
{
	list[0]->previous->next = list[0];
	list[0] = list[0]->previous;
	list[0]->previous->next = NULL;
	ft_putendl_fd("rra", 1);
}

void	re_rotate_b(t_num_list	**b)
{
	b[0]->previous->next = b[0];
	b[0] = b[0]->previous;
	b[0]->previous->next = NULL;
	ft_putendl_fd("rrb", 1);
}

void	rotate_b(t_num_list	**b)
{
	b[0]->previous->next = b[0];
	b[0] = b[0]->next;
	b[0]->previous->next = NULL;
	ft_putendl_fd("rb", 1);
}
