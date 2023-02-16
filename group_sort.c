/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:03:10 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/02/16 18:24:46 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int direction_choose(t_list *stack, int length, int value_to_find)
{
	int		i;
	t_list	*tmp;
	int 	middle;

	i = 0;
	tmp = stack;
	middle = length / 2;
	while (tmp)
	{
		if (((t_nbr *)tmp->content)->nbr != value_to_find)
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
	while(tmp)
	{
		if (((t_nbr *)(tmp->content))->group_id == group_id)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	print_id(t_list stack)
{
	t_list	*tmp;

	tmp = &stack;
	while (tmp)
	{
		printf("%d\n", ((t_nbr *)tmp->content)->group_id);
		tmp = tmp->next;
	}
}
void	group_sort(t_pushswap *data)
{
	int		id;
	// t_list  *tmp;

	id = 0;
	// tmp = data->stack_a;
	while (!is_sorted(data->stack_a) && data->stack_a)
	{
		while (group_check(data->stack_a, id))
		{
			if (((t_nbr *)data->stack_a->content)->group_id == id)
			{
				stack_operation(data, OP_PB, 1);
				stack_operation(data, OP_RB, 1);
			}
			if (((t_nbr *)data->stack_a->content)->group_id == id + 1)
				stack_operation(data, OP_PB, 1);
			else
				stack_operation(data, OP_RA, 1);
		}
		id++;
	}
}