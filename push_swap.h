/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:21:05 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/02/20 16:32:25 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

# include "libft.h"

// Limit marcos

# ifndef INT32_MAX
#  define INT32_MAX 2147483647
# endif
# ifndef INT32_MIN
#  define INT32_MIN -2147483648
# endif

// Operations macros

# define OP_SA "sa"
# define OP_SB "sb"
# define OP_SS "ss"
# define OP_PA "pa"
# define OP_PB "pb"
# define OP_RB "rb"
# define OP_RA "ra"
# define OP_RR "rr"
# define OP_RRA "rra"
# define OP_RRB "rrb"
# define OP_RRR "rrr"

typedef struct s_nbr
{
	int	nbr;
	int	idx;
	int	group_id;
}	t_nbr;

typedef struct s_pushswap
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		length;
	int		group_size;
}	t_pushswap;

void	read_stack(t_pushswap *data, int argc, char **argv);
void	stack_operation(t_pushswap *data, char *operation, int print_operation);

void	radix_binary_sort(t_pushswap *data);
void	small_sort(t_pushswap *data);
void	print_id(t_list stack);
void	this_shit_works(t_pushswap *data);

int		is_sorted(t_list *lst);
void	free_stack(t_pushswap *data);
void	ft_lstswap_content(t_list *a, t_list *b);
void	exit_error(char *err);
void	group_sort(t_pushswap *data);
int		get_smallest_num_idx(t_pushswap *data);

#endif
