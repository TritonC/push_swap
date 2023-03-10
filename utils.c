/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:26:01 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/03/10 11:48:16 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstswap_content(t_list *a, t_list *b)
{
	void	*content;

	content = a->content;
	a->content = b->content;
	b->content = content;
}

void	exit_error(char *err)
{
	ft_putendl_fd(err, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	is_sorted(t_list *lst)
{
	while (lst)
	{
		if (lst->next && ((t_nbr *)lst->content)->idx
			!= ((t_nbr *)lst->next->content)->idx - 1)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	free_stack(t_pushswap *data)
{
	ft_lstclear(&(data->stack_a), free);
	ft_lstclear(&(data->stack_b), free);
}

int	get_smallest_num_idx(t_pushswap *data)
{
	int		smallest_num_idx;
	t_list	*lst;

	smallest_num_idx = data->length - 1;
	lst = data->stack_a;
	while (lst)
	{
		if (((t_nbr *)lst->content)->idx < smallest_num_idx)
			smallest_num_idx = ((t_nbr *)lst->content)->idx;
		lst = lst->next;
	}
	return (smallest_num_idx);
}

void	clear_rotation(t_pushswap *data)
{
	int		i;
	int		min_pos;
	t_list	*head;

	head = data->stack_a;
	i = 0;
	while (((t_nbr *)head->content)->idx != 1)
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