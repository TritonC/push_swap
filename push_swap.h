/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:14:16 by marvin            #+#    #+#             */
/*   Updated: 2022/11/16 22:40:42 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "printf.h"
# include "get_next_line.h"

typedef struct s_dlist
{
	struct s_dlist	*prev;
	int				value;
	struct s_dlist	*next;
	int				min;
	int				max;
}				t_dlist;

int		ft_atoi_pos(char *str, int *pos);
void	rotate(t_dlist **stack, const char choose, char c);
void	swap(t_dlist **a, char c);
void	push(t_dlist **a, t_dlist **b, char c);
t_dlist	*pre_sort(t_dlist *list, int lenght);
int		list_size(t_dlist *list);
void	stack_fill(t_dlist **stack, char **argv);
void	print_stack(t_dlist *list, t_dlist *list2);
t_dlist	*pre_sort2(t_dlist *list, int lenght, t_dlist *last);
t_dlist	*last_node(t_dlist *list);
t_dlist	*insertion_sort(t_dlist *list, int lenght);

#endif