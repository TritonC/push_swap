/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:53:56 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/11/21 16:52:05 by mluis-fu         ###   ########.fr       */
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

t_dlist	*pre_sort(t_dlist *list, t_value *value)
{
	t_dlist	*tmp;
	int		count;
	int		swap;

	tmp = list;
	count = -1;
	while (value->lenght--)
	{
		while (is_sort(list, value->min))
		{
			if (list->value < list->next->value)
			{
				swap = list->value;
				list->value = list->next->value;
				list->next->value = swap;
			}
			list = list->next;
		}
	}
	return (list);
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
