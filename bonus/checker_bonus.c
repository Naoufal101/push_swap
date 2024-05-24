/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:51:54 by nhimad            #+#    #+#             */
/*   Updated: 2024/05/24 12:40:42 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	not_sorted(t_num_list *list)
{
	if (!list)
		return (1);
	while (list->next)
	{
		if (list->number > list->next->number)
			return (1);
		list = list->next;
	}
	return (0);
}

void	same_time(char *str, t_num_list **a, t_num_list **b)
{
	if (!ft_strncmp(str, "rr\n", 3))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strncmp(str, "rrr\n", 4))
	{
		re_rotate(a);
		re_rotate(b);
	}
	else if (!ft_strncmp(str, "ss\n", 3))
	{
		swap(a);
		swap(b);
	}
	else
	{
		l_free(a);
		l_free(b);
		ft_putendl_fd("Error", 2);
		exit(1);
	}
}

void	print_command(char *str, t_num_list **a, t_num_list **b)
{
	if (!ft_strncmp(str, "ra\n", 3))
		rotate(a);
	else if (!ft_strncmp(str, "rra\n", 4))
		re_rotate(a);
	else if (!ft_strncmp(str, "sa\n", 3))
		swap(a);
	else if (!ft_strncmp(str, "pa\n", 3))
		push_a(a, b);
	else if (!ft_strncmp(str, "rb\n", 3))
		rotate(b);
	else if (!ft_strncmp(str, "rrb\n", 4))
		re_rotate(b);
	else if (!ft_strncmp(str, "sb\n", 3))
		swap(b);
	else if (!ft_strncmp(str, "pb\n", 3))
		push_b(a, b);
	else
		same_time(str, a, b);
}

int	main(int c, char **arg)
{
	t_num_list	*a;
	t_num_list	*b;
	char		*str;

	a = 0;
	b = 0;
	str = 0;
	if (c > 1)
	{
		ft_input(arg, &a);
		str = get_next_line(0);
		while (str)
		{
			print_command(str, &a, &b);
			str = get_next_line(0);
		}
		if (not_sorted(a) || b)
		{
			ft_putendl_fd("KO", 1);
		}
		else
			ft_putendl_fd("OK", 1);
		l_free(&a);
		l_free(&b);
	}
}
