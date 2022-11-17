/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:02:13 by marvin            #+#    #+#             */
/*   Updated: 2022/11/02 17:34:43 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_dlist **stack, const char choose, char c)
{
	if (choose == '1')
	{
		*stack = (*stack)->next;
		if (c)
			ft_printf("r%c\n", c);
	}
	else if (choose == '2')
	{
		*stack = (*stack)->prev;
		if (c)
			ft_printf("rr%c\n", c);
	}
}

void	double_rotate(t_dlist **stack_a, t_dlist **stack_b, char c)
{
	if (c == '1')
	{
		rotate(stack_a, '1', '\0');
		rotate(stack_b, '1', '\0');
		ft_printf("rr%c\n", c);
	}
	else if (c == '2')
	{
		rotate(stack_a, '2', '\0');
		rotate(stack_b, '2', '\0');
		ft_printf("rrr\n");
	}
}

void	swap(t_dlist **stack, char c)
{
	t_dlist	*prev;
	t_dlist	*sec;

	prev = (*stack)->prev;
	sec = (*stack)->next;
	prev->next = sec;
	(*stack)->next = sec->next;
	sec->next = (*stack);
	sec->prev = prev;
	(*stack)->prev = sec;
	(*stack) = sec;
	if (c)
		printf("s%c\n", c);
}

void	ss(t_dlist **a, t_dlist **b)
{
	swap(a, '\0');
	swap(b, '\0');
	printf("ss\n");
}

void	push(t_dlist **a, t_dlist **b, char c)
{
	t_dlist	*temp;

	if (c == 'a')
	{
		temp = (*a);
		(*a) = (*b);
		(*b) = (temp);
	}
	temp = NULL;
	(*a)->prev->next = (*a)->next;
	(*a)->next->prev = (*a)->prev;
	if (*b == NULL)
	{
		(*b) = (*a);
		(*a) = (*a)->next;
		(*b)->next = (*b);
		(*b)->prev = (*b);
	}
	else
	{
		temp = (*b);
		(*b) = (*a);
		(*a) = (*a)->next;
		(*b)->next = temp;
		(*b)->prev = temp->prev;
		temp->prev = (*b);
		(*b)->prev->next = (*b);
	}
	printf("p%c\n", c);
}
