/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhimad <nhimad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:39:48 by nhimad            #+#    #+#             */
/*   Updated: 2024/05/25 11:39:55 by nhimad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_list
{
	int				number;
	struct s_list	*next;
	struct s_list	*previous;
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

// functions to sort 2 and 3 numbers
void				sort_three(t_num_list **list);

// function to sort greater lists
void				sort(int *ar, t_num_list **list, t_num_list **b, int l);
void				moves_calculation(t_num_list *b, t_num_list *a, int *array,
						int l);
// make and sort array
int					*ft_array(t_num_list *node, int l);
void				ft_quick_sort(int *array, int start, int end);

//commands function
void				swap(t_num_list **list);
void				push_b(t_num_list **list, t_num_list **b);
void				push_a(t_num_list **list, t_num_list **b);
void				rotate(t_num_list **list);
void				re_rotate(t_num_list **list);
void				re_rotate_b(t_num_list **b);
void				rotate_b(t_num_list **b);

//commands assistant's functions
void				add_b(t_num_list **b, t_num_list *node);
void				push_sort(t_num_list **list, t_num_list **b);
void				perfect_move(t_num_list **al, t_num_list **b);

//general assistant's functions
void				l_free(t_num_list **l);
t_num_list			*f_node(t_num_list *node);
int					list_l(t_num_list *b);

//put the stack in the write position.
void				ft_fix(t_num_list **list, int l);
#endif