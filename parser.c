/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:25:16 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/03/10 10:44:28 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_dup(t_list *lst, int nbr)
{
	while (lst)
	{
		if (nbr == ((t_nbr *)lst->content)->nbr)
			return (1);
		lst = lst->next;
	}
	return (0);
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
		min = INT32_MAX;
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
		((t_nbr *)min_lst->content)->group_id = j;
		i++;
		if (i % data->group_size == 0)
			j++;
	}
}

void	define_group_size(t_pushswap *data)
{
	if (data->length <= 100)
		data->group_size = data->length / 3;
	if (data->length <= 500)
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
		if (tmp > INT32_MAX || tmp < INT32_MIN)
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
	define_group_size(data);
	index_stack(data);
}
