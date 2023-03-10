/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:58:27 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/03/10 11:48:51 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_max(t_pushswap *data)
{
	t_list	*head;

	head = data->stack_b;
	while (((t_nbr *)(head->content))->idx != data->length)
		head = head->next;
	return (head);
}

int	abs_max(int a, int b)
{
	if (abs(a) > abs(b))
		return (abs(a));
	else
		return (abs(b));
}

static void	cost_evaluate(t_pushswap *data)
{
	t_list	*head_b;
	int		cost_a;
	int		cost_b;

	head_b = data->stack_b;
	while (head_b)
	{
		cost_a = ((t_nbr *)(head_b->content))->move.cost_a;
		cost_b = ((t_nbr *)(head_b->content))->move.cost_b;
		if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
			((t_nbr *)(head_b->content))->cost = abs_max(cost_a, cost_b);
		else if (cost_a < 0 && cost_b > 0)
			((t_nbr *)(head_b->content))->cost = abs(cost_a) + cost_b;
		else if (cost_a > 0 && cost_b < 0)
			((t_nbr *)(head_b->content))->cost = cost_a + abs(cost_b);
		else
			((t_nbr *)(head_b->content))->cost = cost_a + cost_b;
		if (((t_nbr *)(head_b->content))->cost < 0)
			((t_nbr *)(head_b->content))->cost *= -1;
		head_b = head_b->next;
	}
}

t_list *max_node(t_pushswap *data)
{
	t_list	*head;

	head = data->stack_b;
	while (((t_nbr *)(head->content))->idx != data->length - 1)
		head = head->next;
	((t_nbr *)(head->content))->move.cost_a = 0;
	return (head);
}

t_list	*best_move(t_pushswap *data)
{
	int		low_cost;
	t_list	*head_b;
	int		size;

	head_b = data->stack_b;
	low_cost = INT32_MAX;
	cost_evaluate(data);
	size = ft_lstsize(head_b) + 3;
	if (size == data->length)
		return (max_node(data));
	while (head_b)
	{
		if (((t_nbr *)(head_b->content))->cost < low_cost)
			low_cost = ((t_nbr *)(head_b->content))->cost;
		head_b = head_b->next;
	}
	head_b = data->stack_b;
	while (low_cost != ((t_nbr *)(head_b->content))->cost)
		head_b = head_b->next;
	return (head_b);
}

void	do_op(t_pushswap *data, char *str, int i, int op)
{
	(void)op;
	stack_operation(data, str, i);
}

void	final2(t_pushswap *data)
{
	t_list	*to_move;
	int		move_a;
	int		move_b;

	to_move = best_move(data);
	move_a = ((t_nbr *)(to_move->content))->move.cost_a;
	move_b = ((t_nbr *)(to_move->content))->move.cost_b;
	while (move_a < 0 && move_b < 0)
		do_op(data, OP_RRR, 1, move_a++ + move_b++);
	while (move_a > 0 && move_b > 0)
		do_op(data, OP_RR, 1, move_a-- + move_b--);
	while (move_a < 0)
		do_op(data, OP_RRA, 1, move_a++);
	while (move_b < 0)
		do_op(data, OP_RRB, 1, move_b++);
	while (move_a > 0)
		do_op(data, OP_RA, 1, move_a--);
	while (move_b > 0)
		do_op(data, OP_RB, 1, move_b--);
	stack_operation(data, OP_PA, 1);
	cost_assign(data);
}

void	final_sort(t_pushswap *data)
{
	int		id;

	if (data->length <= 100)
		id = 3;
	else
		id = 7;
	group_sort(data);
	cost_assign(data);
	// print_this(data->stack_a);
	// printf("\n");
	// print_this(data->stack_b);

	while (data->stack_b)
		final2(data);
	clear_rotation(data);
}