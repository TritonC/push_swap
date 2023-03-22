/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:25:16 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/03/22 11:20:40 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	define_group_size(t_pushswap *data)
{
	if (data->length < 3)
		data->group_size = 1;
	else if (data->length <= 100)
		data->group_size = data->length / 3;
	else if (data->length <= 500)
		data->group_size = data->length / 7;
}

void	init_nbr(t_nbr *nbr)
{
	nbr->idx = -1;
	nbr->group_id = 1;
	nbr->move.cost_a = 0;
	nbr->move.cost_b = 0;
	nbr->cost = 0;
}

void	lst_iter(t_list **lst, t_list **min_lst, int min)
{
	while ((*lst))
	{
		if (min >= ((t_nbr *)(*lst)->content)->nbr
			&& ((t_nbr *)(*lst)->content)->idx < 0)
		{
			min = ((t_nbr *)(*lst)->content)->nbr;
			(*min_lst) = (*lst);
		}
		(*lst) = (*lst)->next;
	}
}

static void	index_stack(t_pushswap *data)
{
	int		i;
	int		j;
	int		min;
	t_list	*lst;
	t_list	*min_lst;

	i = 0;
	j = 1;
	while (i < data->length)
	{
		min_lst = NULL;
		min = INT_MAX;
		lst = data->stack_a;
		lst_iter(&lst, &min_lst, min);
		((t_nbr *)min_lst->content)->idx = i;
		((t_nbr *)min_lst->content)->group_id = j;
		i++;
		if (i % data->group_size == 0)
			j++;
	}
}

void	read_stack(t_pushswap *data, char **argv)
{
	int			i;
	long long	tmp;
	t_nbr		*nbr;
	char		**argv_split;

	i = -1;
	argv_split = split_argv(argv);
	while (argv_split[++i])
	{
		if (!ft_isnbr(argv_split[i]))
			exit_error("Error");
		tmp = ft_atoll(argv_split[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			exit_error("Error");
		if (is_dup(data->stack_a, tmp))
			exit_error("Error");
		nbr = ft_calloc(1, sizeof(t_nbr));
		nbr->nbr = tmp;
		init_nbr(nbr);
		ft_lstadd_back(&data->stack_a, ft_lstnew(nbr));
	}
	ft_memfree((void **)argv_split, NULL);
	data->length = i;
	define_group_size(data);
	index_stack(data);
}
