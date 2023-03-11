/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:56:26 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/03/11 13:32:21 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"

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

void	read_stack(t_pushswap *data, int argc, char **argv);
void	stack_operation(t_pushswap *data, char *operation, int print_operation);
void	exit_error(char *err);
int		is_sorted(t_list *lst);
int		is_dup(t_list *lst, int nbr);
void	ft_lstswap_content(t_list *a, t_list *b);

#endif