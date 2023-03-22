/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:25:16 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/03/22 11:22:37 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		i++;
	}
}

char	**split_argv(char **argv)
{
	int		i;
	char	*dest;
	char	**split;

	i = 1;
	dest = ft_calloc(1, 1);
	while (argv[i])
	{
		dest = ft_strjoin(dest, argv[i]);
		dest = ft_strjoin(dest, " ");
		i++;
	}
	split = ft_split(dest, ' ');
	return (split);
}

void	read_stack(t_pushswap *data, char **argv)
{
	int			i;
	long long	tmp;
	t_nbr		*nbr;
	char		**argv_split;

	i = 0;
	argv_split = split_argv(argv);
	while (argv_split[i])
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
		i++;
	}
	ft_memfree((void **)argv_split, NULL);
	data->length = i;
	index_stack(data);
}
