/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:53:56 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/11/21 19:34:15 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_value(int *a, int *b)
{
	int	*temp;

	temp = a;
	a = b;
	b = temp;
}

int	is_sort(t_dlist *list, int min)
{
	t_dlist	*temp;

	temp = list;
	while (list->value != min)
		list = list->next;
	while (min != list->next->value)
	{
		if (list->value < list->next->value)
			list = list->next;
		else
			return (false);
	}
	return (true);
}

t_dlist	*pre_sort(t_dlist *list, t_value *value)
{
	t_dlist	*tmp;
	t_dlist	*lst_min;
	int		swap;
	int		ite;

	tmp = list;
	ite = value->lenght;
	while (!(is_sort(list, value->min)))
	{

		while ((list->value > list->next->value) || ite)
		{
			swap = list->value;
			list->value = list->next->value;
			list->next->value = swap;
			list = list->next;
			ite--;
		}
		list = tmp;
		ite = 0;
	}
	return (list);
}
