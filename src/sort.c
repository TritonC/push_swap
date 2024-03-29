/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:46:05 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/04/02 12:56:56 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*function to sort the stack_a when the stack_a has 3 nodes*/
void	sort_3(t_pushswap *data)
{
	if (((t_nbr *)data->stack_a->content)->idx == data->length - 1)
		stack_operation(data, OP_RA, 1);
	else if (((t_nbr *)data->stack_a->next->content)->idx == data->length - 1)
		stack_operation(data, OP_RRA, 1);
	if (((t_nbr *)data->stack_a->content)->idx
		> ((t_nbr *)data->stack_a->next->content)->idx)
		stack_operation(data, OP_SA, 1);
}

/*this function rotate the smallest number to the top of the stack_a*/
static void	rotate_smallest_to_top(t_pushswap *data)
{
	int		smallest_num_idx;
	int		idx_in_stack;
	t_list	*lst;

	smallest_num_idx = get_smallest_num_idx(data);
	lst = data->stack_a;
	idx_in_stack = 0;
	while (lst)
	{
		if (((t_nbr *)lst->content)->idx == smallest_num_idx)
			break ;
		idx_in_stack++;
		lst = lst->next;
	}
	while (((t_nbr *)data->stack_a->content)->idx != smallest_num_idx)
	{
		if (idx_in_stack > ft_lstsize(data->stack_a) / 2)
			stack_operation(data, OP_RRA, 1);
		else
			stack_operation(data, OP_RA, 1);
	}
}

/*call the previous functions to sort the stack_a*/
void	small_sort(t_pushswap *data)
{
	while (ft_lstsize(data->stack_a) > 3)
	{
		rotate_smallest_to_top(data);
		stack_operation(data, OP_PB, 1);
	}
	if (ft_lstsize(data->stack_a) <= 3)
		sort_3(data);
	while (data->stack_b)
		stack_operation(data, OP_PA, 1);
}

void	do_op(t_pushswap *data, char *str, int i, int op)
{
	(void)op;
	stack_operation(data, str, i);
}

void	sort(t_pushswap *data)
{
	int	max_idx;
	t_list	*tmp;

	tmp = data->stack_a;
	max_idx = INT_MIN;
	while (tmp)
	{
		if (max_idx < ((t_nbr *)tmp->content)->idx)
			max_idx = ((t_nbr *)tmp->content)->idx;
		tmp = tmp->next;
	}
	if (((t_nbr *)data->stack_a->content)->idx == max_idx)
		stack_operation(data, OP_RA, 1);
	else if (((t_nbr *)data->stack_a->next->content)->idx == max_idx)
		stack_operation(data, OP_RRA, 1);
	if (((t_nbr *)data->stack_a->content)->idx
		> ((t_nbr *)data->stack_a->next->content)->idx)
		stack_operation(data, OP_SA, 1);
}