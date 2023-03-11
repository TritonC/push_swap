/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:54:40 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/03/11 13:32:13 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exit_error(char *err)
{
	ft_putendl_fd(err, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_lstswap_content(t_list *a, t_list *b)
{
	void	*content;

	content = a->content;
	a->content = b->content;
	b->content = content;
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
