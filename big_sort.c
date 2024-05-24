/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:40:58 by nhimad            #+#    #+#             */
/*   Updated: 2024/05/22 15:15:09 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	*ft_array(t_num_list *node, int l)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * l);
	if (!array)
		exit(1);
	i = 0;
	while (node)
	{
		array[i] = node->number;
		node = node->next;
		i++;
	}
	ft_quick_sort(array, 0, l - 1);
	return (array);
}

int	averages(int *array, int l)
{
	return (array[l / 2]);
}

void	sort(int *ar, t_num_list **list, t_num_list **b, int l)
{
	int	average;
	int	lats_number;
	int	current_number;

	average = averages(ar, l);
	lats_number = list[0]->previous->number;
	while (l > 3)
	{
		current_number = list[0]->number;
		if (current_number <= average)
		{
			push_b(list, b);
			l--;
		}
		else if (current_number > average)
			rotate(list);
		if (current_number == lats_number)
		{
			lats_number = list[0]->previous->number;
			average = averages(&ar[list_l(b[0])], l);
		}
	}
	free(ar);
	sort_three(list);
	push_sort(list, b);
}
