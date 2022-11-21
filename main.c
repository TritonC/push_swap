/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:09:51 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/11/21 16:41:42 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_dlist **list, t_value *value)
{
	value->min = INT_MAX;
	value->max = INT_MIN;
	value->lenght = 0;
	get_values((*list), value);
}

int	main(int argc, char **argv)
{
	t_dlist	*stack_a;
	t_dlist	*testing;
	t_value	value;

	(void) argc;
	stack_a = NULL;
	testing = NULL;
	stack_fill(&testing, argv);
	stack_fill(&stack_a, argv);
	init(&stack_a, &value);
	print_stack(stack_a, testing);
	printf("min = %d \t\tmax = %d\t\tlenght = %d\n",
		value.min, value.max, value.lenght);
	if (is_sort(stack_a, value.min))
	{
		printf ("list is sorted\n");
		return (0);
	}
	else
	{
		printf("list is not sorted\n");
		return (0);
	}
}
