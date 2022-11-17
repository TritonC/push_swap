/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:53:56 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/11/16 22:40:05 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*pre_sort(t_dlist *list, int lenght)
{
	int		sort;
	int		first_value;
	t_dlist	*temp;
	int		count;
	int		count_y;

	temp = list;
	first_value = list->value;
	count_y = lenght * 110;
	while (count_y--)
	{
		count = -1;
		while (++count < lenght)
		{
			if (list->value > list->next->value)
			{
				sort = list->value;
				list->value = list->next->value;
				list->next->value = sort;
				list = temp;
			}
			list = list->next;
		}
	}
	return (temp->prev);
}

t_dlist	*insertion_sort(t_dlist *list, int lenght)
{
	int		i;
	int		j;
	int		value;
	int		iterate_count;
	t_dlist	*temp;

	iterate_count = lenght * 100;
	i = 0;
	temp = list;
	while (iterate_count--)
	{
		while (++i < lenght)
		{
			value = list->value;
			j = i - 1;
			while (j <= 0 && list->value > value)
			{
				list->next->value = value;
				j = j - 1;
			}
			list->next->value = value;
			list = list->next;
		}
	}
	return (temp);
}