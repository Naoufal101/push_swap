/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_calculation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:38:32 by nhimad            #+#    #+#             */
/*   Updated: 2024/05/25 11:38:59 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mc_supporter(t_num_list *b, t_num_list *a, int *c)
{
	while (a->previous->next && b->number < a->previous->number)
	{
		a = a->previous;
		(*c)++;
	}
}

void	mc_supporter2(t_num_list *b, t_num_list *a, int *c)
{
	while (a && b->number > a->number)
	{
		a = a->next;
		(*c)++;
	}
}

void	moves_calculation(t_num_list *b, t_num_list *a, int *array, int l)
{
	int	i;
	int	c;

	i = 0;
	while (b && i < l)
	{
		c = 0;
		if (b->number < a->number)
			mc_supporter(b, a, &c);
		else
			mc_supporter2(b, a, &c);
		b = b->next;
		if (i <= (l / 2))
			array[i] = i + c;
		else
			array[i] = (l - i) + c;
		i++;
	}
}
