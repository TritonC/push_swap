/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:09:51 by mluis-fu          #+#    #+#             */
/*   Updated: 2022/11/16 22:40:58 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dlist	*stack_a;
	t_dlist	*testing;
	int		lenght;

	(void) argc;
	stack_a = NULL;
	testing = NULL;
	stack_fill(&testing, argv);
	stack_fill(&stack_a, argv);
	lenght = list_size(testing);
//	testing = pre_sort(testing, lenght);
	testing = insertion_sort(testing, lenght);
	print_stack(stack_a, testing);
	stack_a->min = testing->value;
	stack_a->max = testing->prev->value;
	printf("min = %d \t\tmax = %d\n", stack_a->min, stack_a->max);
}
