/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfect_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:49:03 by nhimad            #+#    #+#             */
/*   Updated: 2024/05/18 19:58:01 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	move_b(t_num_list **b, int c, int l)
{
	if (c <= (l / 2))
	{
		while (c)
		{
			rotate_b(b);
			c--;
		}
	}
	else
	{
		while (l - c)
		{
			re_rotate_b(b);
			c++;
		}
	}
}

int	target(int *array, int i)
{
	int	j;
	int	c;

	j = 0;
	c = 0;
	while (j < i)
	{
		if (array[j] < array[c])
			c = j;
		j++;
	}
	return (c);
}

void	perfect_move(t_num_list **al, t_num_list **b)
{
	int	*array;
	int	l;
	int	c;

	l = list_l(b[0]);
	array = malloc(sizeof(int) * l);
	if (!array)
		return ;
	moves_calculation(b[0], al[0], array, l);
	c = target(array, l);
	move_b(b, c, l);
	free(array);
}
