/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:26:31 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/03/13 10:36:04 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_pushswap	data;

	if (argc <= 3)
		return (EXIT_SUCCESS);
	data.stack_a = NULL;
	data.stack_b = NULL;
	read_stack(&data, argc, argv);
	if (is_sorted(data.stack_a))
	{
		free_stack(&data);
		return (EXIT_SUCCESS);
	}
	if (data.length <= 5)
		small_sort(&data);
	else
		final_sort(&data);
	free_stack(&data);
	return (1);
}
