/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:03:10 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/03/10 13:18:28 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	group_check(t_list *stack, int group_id)
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
	int		lst_size;

	id = 1;
	lst_size = ft_lstsize(data->stack_b);
	while (lst_size != 3)
	{
		while (group_check(data->stack_a, id) && lst_size != 3)
		{
			if (((t_nbr *)data->stack_a->content)->group_id == id)
				stack_operation(data, OP_PB, 1);
			if (data->stack_a && ((t_nbr *)data->stack_a->content)
				->group_id == id + 1)
			{
				stack_operation(data, OP_PB, 1);
				stack_operation(data, OP_RB, 1);
			}
			else
				stack_operation(data, OP_RRA, 1);
			lst_size = ft_lstsize(data->stack_a);
		}
		id++;
	}
//	data->length = ft_lstsize(data->stack_a);
	sort_3(data);
}

int	get_lower_idx(t_list *stack_a, int idx_from_b)
{
	int		idx_pos_max;
	int		idx_pos;
	t_list	*head;

	head = stack_a;
	idx_pos = INT_MAX;
	idx_pos_max = INT_MAX;
	while (head)
	{
		if (idx_pos_max > idx_pos)
			idx_pos_max = idx_pos;
		if (((t_nbr *)(head->content))->idx > idx_from_b
			&& ((t_nbr *)(head->content))->idx < idx_pos)
			idx_pos = ((t_nbr *)(head->content))->idx;
		head = head->next;
	}
	if (idx_pos == INT_MAX)
		idx_pos = idx_pos_max;
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

// function to mark the cost in A and B, for every node in the stack_b
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
		((t_nbr *)(head_b->content))->move.cost_a = c_value(data->stack_a, i);
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
	int		total_cost;
	int		id;
	t_list	*head;

	head = stack;
	while (head)
	{
		cost_a = ((t_nbr *)(head->content))->move.cost_a;
		cost_b = ((t_nbr *)(head->content))->move.cost_b;
		nbr_value = ((t_nbr *)(head->content))->nbr;
		idx = ((t_nbr *)(head->content))->idx;
		id = ((t_nbr *)(head->content))->group_id;
		total_cost = ((t_nbr *)(head->content))->cost;
		printf("nbr | idx | id | cost_a | cost_b | total_cost\n%d | %d | %d | %d | %d | %d\n", nbr_value, idx, id, cost_a, cost_b, total_cost);
		head = head->next;
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