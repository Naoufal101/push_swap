/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:21:12 by nhimad            #+#    #+#             */
/*   Updated: 2024/05/24 12:40:17 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	error_free(char **arg, t_num_list **a)
{
	l_free(a);
	ft_free(arg);
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	ft_isint(long n, char **arg, t_num_list **a)
{
	if (n < INT_MIN || n > INT_MAX)
		error_free(arg, a);
	return (n);
}

int	ft_sign(char **arg, t_num_list **a, int i)
{
	if ((arg[i][0] == '+' || arg[i][0] == '-') && !arg[i][1])
		error_free(arg, a);
	if (arg[i][0] == '+' || arg[i][0] == '-')
		return (1);
	return (0);
}

void	ft_search(char **arg, t_num_list **a, int number)
{
	t_num_list	*list;

	list = *a;
	while (list)
	{
		if (list->number == number)
			error_free(arg, a);
		list = list->next;
	}
}
