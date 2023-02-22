/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:03:10 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/02/22 19:25:51 by mluis-fu         ###   ########.fr       */
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
	while (tmp && tmp->next)
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
	int		lst_size;

	id = 1;
	lst_size = ft_lstsize(data->stack_b);
	while (lst_size != 3)
	{
		while (group_check(data->stack_a, id) && lst_size != 3)
		{
			lst_size = ft_lstsize(data->stack_a);
			if (((t_nbr *)data->stack_a->content)->group_id == id)
				stack_operation(data, OP_PB, 1);
			if (data->stack_a && ((t_nbr *)data->stack_a->content)->group_id == id + 1)
			{
				stack_operation(data, OP_PB, 1);
				stack_operation(data, OP_RB, 1);
			}
			else
				stack_operation(data, OP_RRA, 1);
		}
		id++;
	}
	sort_3(data);
}

int	get_lower_idx(t_list *stack_a, int idx_from_b)
{
	int		idx_pos;
	t_list	*head;

	head = stack_a;
	idx_pos = INT32_MAX;
	while (head)
	{
		if (((t_nbr *)(head->content))->idx > idx_from_b
			&& ((t_nbr *)(head->content))->idx < idx_pos)
			idx_pos = ((t_nbr *)(head->content))->idx;
		head = head->next;
	}
	if (idx_pos == INT32_MAX)
		idx_pos = idx_from_b;
	return (idx_pos);
}

int	c_value(t_list *stack, int i)
{
	int	cost;

	cost = i;
	if (i > ft_lstsize(stack) / 2)
		cost = i - ft_lstsize(stack);
	return (cost);
}

t_list	*best_move(t_list *stack)
{
	int		best_a;
	int		best_b;
	int		lower_cost;
	t_list	*head;

	head = stack;
	while (head)
	{
		best_a = ((t_nbr *)(head->content))->move.cost_a;
		best_b = ((t_nbr *)(head->content))->move.cost_b;
		if (best_a < 0 && best_b < 0)
			lower_cost = (best_a * -1) + best_b;
}

void	cost_assign(t_pushswap *data)
{
	int		i;
	int		j;
	int		idx_pos;
	t_list	*head_a;
	t_list	*head_b;

	j = 0;
	head_b = data->stack_b;
	while (head_b)
	{
		i = 0;
		head_a = data->stack_a;
		idx_pos = get_lower_idx(data->stack_a,
				((t_nbr *)(head_b->content))->idx);
		while (head_a && ((t_nbr *)(head_a->content))->idx != idx_pos)
		{
			i++;
			head_a = head_a->next;
		}
		((t_nbr *)(head_b->content))->move.cost_b = c_value(data->stack_b, j);
		((t_nbr *)(head_b->content))->move.cost_a = c_value(data->stack_b, i);
		head_b = head_b->next;
		j++;
	}
}

void	print_this(t_list *stack)
{
	int		idx;
	int		cost_a;
	int		cost_b;
	int		nbr_value;
	t_list	*head;

	head = stack;
	while (head)
	{
		cost_a = ((t_nbr *)(head->content))->move.cost_a;
		cost_b = ((t_nbr *)(head->content))->move.cost_b;
		nbr_value = ((t_nbr *)(head->content))->nbr;
		idx = ((t_nbr *)(head->content))->idx;
		printf("nbr | idx | cost_a | cost_b\n%d | %d | %d | %d\n", nbr_value, idx, cost_a, cost_b);
		head = head->next;
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
	cost_assign(data);
	print_this(data->stack_b);
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