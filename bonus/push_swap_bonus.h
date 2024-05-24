/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:39:48 by nhimad            #+#    #+#             */
/*   Updated: 2024/05/24 12:50:26 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

typedef struct n_list
{
	int				number;
	struct n_list	*next;
	struct n_list	*previous;
}					t_num_list;

// free the arg and list, and print the "error" message.
void				ft_free(char **str);
void				error_free(char **arg, t_num_list **a);

// filter the input
int					ft_isint(long n, char **arg, t_num_list **a);
int					ft_sign(char **arg, t_num_list **a, int i);
void				ft_search(char **arg, t_num_list **a, int number);

// take the filtered input and put them in (stack) a.
void				ft_fill_list(char **arg, t_num_list **a);
int					l_add_back(t_num_list **list, int n);
void				ft_input(char **arg, t_num_list **a);

//commands functions
void				push_a(t_num_list **list, t_num_list **b);
void				push_b(t_num_list **list, t_num_list **b);
void				swap(t_num_list **list);
void				rotate(t_num_list **list);
void				re_rotate(t_num_list **list);

//get list size
int					list_l(t_num_list *b);

//free list
void				l_free(t_num_list **l);
#endif