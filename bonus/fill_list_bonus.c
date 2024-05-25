/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:21:25 by nhimad            #+#    #+#             */
/*   Updated: 2024/05/25 15:13:31 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	l_free(t_num_list **l)
{
	while (l[0])
	{
		if (l[0]->next)
		{
			l[0] = l[0]->next;
			free(l[0]->previous);
		}
		else
		{
			free(l[0]);
			l[0] = NULL;
		}
	}
}

int	check_number(char **arg, t_num_list **a, int i)
{
	int	bool;
	int	c;
	int	j;

	c = 0;
	bool = 0;
	j = ft_sign(arg, a, i);
	while (arg[i][j])
	{
		if (!ft_isdigit(arg[i][j]))
			error_free(arg, a);
		if (bool)
			c++;
		else if (arg[i][j] != '0')
			bool = 1;
		j++;
	}
	return (c);
}

void	ft_fill_list(char **arg, t_num_list **a)
{
	int	i;
	int	count;
	int	number;

	i = 0;
	while (arg[i])
	{
		count = check_number(arg, a, i);
		number = ft_isint(ft_atol(arg[i]), arg, a);
		ft_search(arg, a, number);
		if (count > 11 || l_add_back(a, number))
			error_free(arg, a);
		i++;
	}
}

void	ft_input(char **arg, t_num_list **a)
{
	int		i;
	char	**sarg;

	i = 1;
	sarg = NULL;
	while (arg[i])
	{
		sarg = ft_split(arg[i], ' ');
		if (!sarg || !sarg[0])
			error_free(sarg, a);
		ft_fill_list(sarg, a);
		ft_free(sarg);
		i++;
	}
}
