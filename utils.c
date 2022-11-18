/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:53:56 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/11/17 12:21:10 by mluis-fu         ###   ########.fr       */
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

t_dlist	*pre_sort(t_dlist *list, int lenght)
{
	int		first_value;
	t_dlist	*temp;
	int		count;
	int		count_y;
	int		swap;

	temp = list;
	first_value = list->value;
	count_y = lenght;
	while (count_y--)
	{
		count = 0;
		while (count < lenght)
		{
			if (list->value > list->next->value)
			{
				swap = list->value;
				list->value = list->next->value;
				list->next->value = swap;
				list = temp;
			}
			list = list->next;
			count++;
		}
		list = temp;
	}
	return (temp);
}
