/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:30:11 by nhimad            #+#    #+#             */
/*   Updated: 2024/05/24 12:03:56 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

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

char	not_sorted(t_num_list *list)
{
	while (list->next)
	{
		if (list->number > list->next->number)
			return (1);
		list = list->next;
	}
	return (0);
}

void	sort_three(t_num_list **list)
{
	if ((list[0]->number > (list[0]->previous)->number)
		&& (list[0]->number > (list[0]->next)->number))
		rotate(list);
	else if ((list[0]->next)->number > (list[0]->previous)->number)
		re_rotate(list);
	if (list[0]->number > (list[0]->next)->number)
		swap(list);
}

int	main(int c, char **arg)
{
	t_num_list	*a;
	t_num_list	*b;
	int			l;

	a = 0;
	b = 0;
	if (c > 1)
	{
		ft_input(arg, &a);
		l = list_l(a);
		if (l <= 3 && not_sorted(a))
			sort_three(&a);
		else if (not_sorted(a))
		{
			sort(ft_array(a, l), &a, &b, l);
			ft_fix(&a, l);
		}
		l_free(&a);
	}
	return (0);
}
