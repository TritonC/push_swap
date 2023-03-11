/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 05:40:14 by cthien-h          #+#    #+#             */
/*   Updated: 2022/03/17 08:07:16 by cthien-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_operator(char *line)
{
	if (!ft_strncmp(line, OP_PA, ft_strlen(OP_PA) + 1)
		|| !ft_strncmp(line, OP_PB, ft_strlen(OP_PB) + 1)
		|| !ft_strncmp(line, OP_RA, ft_strlen(OP_RA) + 1)
		|| !ft_strncmp(line, OP_RB, ft_strlen(OP_RB) + 1)
		|| !ft_strncmp(line, OP_RR, ft_strlen(OP_RR) + 1)
		|| !ft_strncmp(line, OP_RRA, ft_strlen(OP_RRA) + 1)
		|| !ft_strncmp(line, OP_RRB, ft_strlen(OP_RRB) + 1)
		|| !ft_strncmp(line, OP_RRR, ft_strlen(OP_RRR) + 1)
		|| !ft_strncmp(line, OP_SA, ft_strlen(OP_SA) + 1)
		|| !ft_strncmp(line, OP_SB, ft_strlen(OP_SB) + 1)
		|| !ft_strncmp(line, OP_SS, ft_strlen(OP_SS) + 1))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_pushswap	data;
	char		*line;

	if (argc == 1)
		return (EXIT_SUCCESS);
	data.stack_a = NULL;
	data.stack_b = NULL;
	read_stack(&data, argc, argv);
	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (!is_operator(line))
			exit_error("Error");
		stack_operation(&data, line, 0);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	if (is_sorted(data.stack_a) && data.stack_b == NULL)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	free_stack(&data);
	return (EXIT_SUCCESS);
}
