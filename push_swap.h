/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:14:16 by marvin            #+#    #+#             */
/*   Updated: 2022/11/21 16:58:25 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include "printf.h"
# include "get_next_line.h"
# include <stdbool.h>

typedef struct s_dlist
{
	struct s_dlist	*prev;
	int				value;
	struct s_dlist	*next;
}				t_dlist;

typedef struct s_values
{
	int				min;
	int				max;
	int				lenght;
}				t_value;

int		ft_atoi_pos(char *str, int *pos);
void	rotate(t_dlist **stack, const char choose, char c);
void	swap(t_dlist **a, char c);
void	push(t_dlist **a, t_dlist **b, char c);
t_dlist	*pre_sort(t_dlist *list, t_value *value);
int		list_size(t_dlist **list);
void	stack_fill(t_dlist **stack, char **argv);
void	print_stack(t_dlist *list, t_dlist *list2);
t_dlist	*last_node(t_dlist *list);
void	get_values(t_dlist *list, t_value *values);
int		is_sort(t_dlist *list, int min);

#endif