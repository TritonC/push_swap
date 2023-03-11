/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:24:43 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/02/15 12:24:47 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_swap(t_list *stack)
{
	t_list	*second;

	if (stack)
	{
		second = stack->next;
		if (second)
			ft_lstswap_content(stack, second);
	}
}

static void	stack_push(t_list **stack_from, t_list **stack_to)
{
	t_list	*tmp;

	if (*stack_from)
	{
		tmp = (*stack_from)->next;
		(*stack_from)->next = *stack_to;
		*stack_to = *stack_from;
		*stack_from = tmp;
	}
}

static void	stack_rotate(t_list **stack)
{
	t_list	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = NULL;
		ft_lstadd_back(stack, tmp);
	}
}

static void	stack_rrotate(t_list **stack)
{
	t_list	*current;
	t_list	*prev;

	if (*stack && (*stack)->next)
	{
		current = *stack;
		while (current->next)
		{
			prev = current;
			current = current->next;
		}
		prev->next = NULL;
		ft_lstadd_front(stack, current);
	}
}

void	stack_operation(t_pushswap *data, char *operation, int print_operation)
{
	if (!ft_strncmp(operation, OP_SA, ft_strlen(OP_SA))
		|| !ft_strncmp(operation, OP_SS, ft_strlen(OP_SS) + 1))
		stack_swap(data->stack_a);
	if (!ft_strncmp(operation, OP_SB, ft_strlen(OP_SB))
		|| !ft_strncmp(operation, OP_SS, ft_strlen(OP_SS) + 1))
		stack_swap(data->stack_b);
	if (!ft_strncmp(operation, OP_PA, ft_strlen(OP_PA)))
		stack_push(&data->stack_b, &data->stack_a);
	else if (!ft_strncmp(operation, OP_PB, ft_strlen(OP_PB) + 1))
		stack_push(&data->stack_a, &data->stack_b);
	if (!ft_strncmp(operation, OP_RA, ft_strlen(OP_RA))
		|| !ft_strncmp(operation, OP_RR, ft_strlen(OP_RR) + 1))
		stack_rotate(&data->stack_a);
	if (!ft_strncmp(operation, OP_RB, ft_strlen(OP_RB))
		|| !ft_strncmp(operation, OP_RR, ft_strlen(OP_RR) + 1))
		stack_rotate(&data->stack_b);
	if (!ft_strncmp(operation, OP_RRA, ft_strlen(OP_RRA))
		|| !ft_strncmp(operation, OP_RRR, ft_strlen(OP_RRR) + 1))
		stack_rrotate(&data->stack_a);
	if (!ft_strncmp(operation, OP_RRB, ft_strlen(OP_RRB))
		|| !ft_strncmp(operation, OP_RRR, ft_strlen(OP_RRR) + 1))
		stack_rrotate(&data->stack_b);
	if (print_operation)
		ft_putendl_fd(operation, STDOUT_FILENO);
}
