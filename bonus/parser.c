/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:25:16 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/03/13 08:07:19 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_nbr(t_nbr *nbr)
{
	nbr->idx = -1;
	nbr->group_id = 1;
	nbr->move.cost_a = 0;
	nbr->move.cost_b = 0;
	nbr->cost = 0;
}

static void	index_stack(t_pushswap *data)
{
	int		i;
	int		min;
	t_list	*lst;
	t_list	*min_lst;

	i = 0;
	while (i < data->length)
	{
		min_lst = NULL;
		min = INT_MAX;
		lst = data->stack_a;
		while (lst)
		{
			if (min >= ((t_nbr *)lst->content)->nbr
				&& ((t_nbr *)lst->content)->idx < 0)
			{
				min = ((t_nbr *)lst->content)->nbr;
				min_lst = lst;
			}
			lst = lst->next;
		}
		((t_nbr *)min_lst->content)->idx = i;
	}
}

void	read_stack(t_pushswap *data, int argc, char **argv)
{
	int			i;
	long long	tmp;
	t_nbr		*nbr;

	data->length = argc - 1;
	i = 1;
	while (i < argc)
	{
		if (!ft_isnbr(argv[i]))
			exit_error("Error");
		tmp = ft_atoll(argv[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			exit_error("Error");
		if (is_dup(data->stack_a, tmp))
			exit_error("Error");
		nbr = ft_calloc(1, sizeof(t_nbr));
		if (!nbr)
			exit_error("Error");
		nbr->nbr = tmp;
		init_nbr(nbr);
		ft_lstadd_back(&data->stack_a, ft_lstnew(nbr));
		i++;
	}
	index_stack(data);
}
