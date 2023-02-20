/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:03:10 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/02/20 18:45:58 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int direction_choose(t_list *stack, int length, int index_to_find)
{
	int		i;
	t_list	*tmp;
	int 	middle;

	i = 0;
	tmp = stack;
	middle = length / 2;
	while (tmp)
	{
		if (((t_nbr *)tmp->content)->idx != index_to_find)
			i++;
		tmp = tmp->next;
	}
	if (i < middle)
		return (1);
	else
		return (2);
}

int		group_check(t_list *stack, int group_id)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (((t_nbr *)(tmp->content))->group_id == group_id)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	group_sort(t_pushswap *data)
{
	int		id;

	id = 1;
	while (!is_sorted(data->stack_a) && data->stack_a)
	{
		while (group_check(data->stack_a, id) && data->stack_a)
		{
			if (((t_nbr *)data->stack_a->content)->group_id == id)
				stack_operation(data, OP_PB, 1);
			if (data->stack_a && ((t_nbr *)data->stack_a->content)->group_id == id + 1)
			{
				stack_operation(data, OP_PB, 1);
				stack_operation(data, OP_RB, 1);
			}
			else if (data->stack_a)
				stack_operation(data, OP_RRA, 1);
		}
		id++;
	}
}

int	index_value(t_list *stack, int id)
{
	t_list	*tmp;
	int		index_to_find;

	index_to_find = INT32_MIN;
	tmp = stack;
	while (tmp)
	{
		if (((t_nbr *)(tmp->content))->idx > index_to_find
			&& ((t_nbr *)(tmp->content))->group_id == id)
			index_to_find = ((t_nbr *)(tmp->content))->idx;
		tmp = tmp->next;
	}
	return (index_to_find);
}

int	idx_pos(t_list *stack, int idx_to_find)
{
	t_list	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		if (((t_nbr *)tmp->content)->idx == idx_to_find)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

void	empty_b(t_pushswap *data, int id)
{
	int		middle_size;
	int		idx_to_move;
	int		idx;
	int		top;

	while (group_check(data->stack_b, id))
	{
		middle_size = ft_lstsize(data->stack_b) / 2;
		idx_to_move = index_value(data->stack_b, id);
		idx = idx_pos(data->stack_b, idx_to_move);
		top = ft_lstsize(data->stack_b);
		if (idx > middle_size)
			while (idx++ != top)
				stack_operation(data, OP_RRB, 1);
		else
			while (idx-- != 0)
				stack_operation(data, OP_RB, 1);
		stack_operation(data, OP_PA, 1);
	}
}


void	this_shit_works(t_pushswap *data)
{
	int		cost;
	int		id;
	int		move_cost;

	cost = 0;
	move_cost = 0;
	if (data->length <= 100)
		id = 3;
	else
		id = 7;
	group_sort(data);
	while (id > 0)
	{
		empty_b(data, id);
		id--;
	}
}
/*
void	final_step(t_pushswap *data)
{
	int		cost;
	int		max_id;
	int		move_cost;

	cost = 0;
	move_cost = 0;
	if (data->length <= 100)
		max_id = 3;
	else
		max_id = 7;
	while (data->stack_b)
	{
		while (group_check(data->stack_b, max_id))
		{
			
		}
	}
}*/

/*
500

256
-500 
-44
if( move < 0)

if (move )

cost 10
cost 7
cost < min mov
2 1 3 4 5 .... 500

0 0 1 1
0 0 0 1

<< 1
<< 2

500
*/