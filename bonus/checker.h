/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:56:26 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/03/13 13:41:29 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "limits.h"

# include "stdio.h"

# include "../inc/libft/libft.h"

typedef struct s_move
{
	int	cost_a;
	int	cost_b;
}	t_move;

typedef struct s_nbr
{
	int		nbr;
	int		idx;
	int		group_id;
	int		cost;
	t_move	move;
}	t_nbr;

typedef struct s_pushswap
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		length;
	int		group_size;
}	t_pushswap;

# define OP_SA "sa\n"
# define OP_SB "sb\n"
# define OP_SS "ss\n"
# define OP_PA "pa\n"
# define OP_PB "pb\n"
# define OP_RB "rb\n"
# define OP_RA "ra\n"
# define OP_RR "rr\n"
# define OP_RRA "rra\n"
# define OP_RRB "rrb\n"
# define OP_RRR "rrr\n"

void	read_stack(t_pushswap *data, char **argv);
void	free_stack(t_pushswap *data);
void	stack_operation(t_pushswap *data, char *operation, int print_operation);
void	exit_error(char *err);
int		is_sorted(t_list *lst);
int		is_dup(t_list *lst, int nbr);
void	ft_lstswap_content(t_list *a, t_list *b);

#endif