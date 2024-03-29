/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:58:27 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/04/02 12:53:48 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*function to calculate the cost of moving the node from stack_b to stack_a*/

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

/*function to get the node with the highest index*/
t_list	*max_node(t_pushswap *data)
{
	t_list	*head;

	head = data->stack_b;
	while (((t_nbr *)(head->content))->idx != data->length - 1)
		head = head->next;
	((t_nbr *)(head->content))->move.cost_a = 0;
	return (head);
}

/*function to get the node with lower cost*/

t_list	*best_move(t_pushswap *data)
{
	int		low_cost;
	t_list	*head_b;

	head_b = data->stack_b;
	low_cost = INT_MAX;
	cost_evaluate(data);
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

/*function that execute the movement of the node with lower cost*/
void	final(t_pushswap *data)
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

/*function that execute all the prevoius functions*/
void	final_sort(t_pushswap *data)
{
	group_sort(data);
	cost_assign(data);
	while (data->stack_b)
		final2(data);
	clear_rotation(data);
}
