/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:19:23 by nhimad            #+#    #+#             */
/*   Updated: 2024/05/22 13:08:21 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_quick_sort(int *array, int start, int end)
{
	int	pivot;
	int	i;

	if (start > end)
		return ;
	i = start - 1;
	pivot = array[end];
	while (start <= end)
	{
		if (array[start] <= pivot)
		{
			i++;
			ft_swap(array + i, array + start);
		}
		start++;
	}
	ft_quick_sort(array, 0, i - 1);
	ft_quick_sort(array, i + 1, end);
}
