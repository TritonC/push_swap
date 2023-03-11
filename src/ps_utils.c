/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 09:14:34 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/03/11 09:24:18 by mluis-fu         ###   ########.fr       */
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

int	is_dup(t_list *lst, int nbr)
{
	while (lst)
	{
		if (nbr == ((t_nbr *)lst->content)->nbr)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	clear_rotation(t_pushswap *data)
{
	int		i;
	t_list	*head;

	head = data->stack_a;
	i = 0;
	while (((t_nbr *)head->content)->idx != 0)
	{
		i++;
		head = head->next;
	}
	if (i > ft_lstsize(data->stack_a) / 2)
		i = i - ft_lstsize(data->stack_a);
	while (i > 0)
		do_op(data, OP_RA, 1, i--);
	while (i < 0)
		do_op(data, OP_RRA, 1, i++);
}
