/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:16:09 by marvin            #+#    #+#             */
/*   Updated: 2022/11/21 15:52:43 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*create_node(int n)
{
	t_dlist	*element;

	element = (t_dlist *)malloc(sizeof(t_dlist));
	if (element)
	{
		element->value = n;
		element->next = element;
		element->prev = element;
	}
	return (element);
}

int	list_size(t_dlist **list)
{
	int		count;
	int		val;
	t_dlist	*next;

	count = 1;
	val = (*list)->value;
	next = (*list)->next;
	while (val != next->value)
	{
		next = next->next;
		count++;
	}
	return (count);
}

void	get_values(t_dlist *list, t_value *value)
{
	int		count;
	int		first;
	t_dlist	*temp;

	temp = list;
	count = 1;
	first = list->value;
	while (1)
	{
		if (list->value < value->min)
			value->min = list->value;
		if (list->value > value->max)
			value->max = list->value;
		if (first == list->next->value)
			break ;
		list = list->next;
		count++;
	}
	list = temp;
	value->lenght = count;
}

t_dlist	*last_node(t_dlist *list)
{
	t_dlist	*last_node;
	int		lst_size;

	lst_size = list_size(&list) - 1;
	last_node = list;
	while (lst_size--)
		last_node = last_node->next;
	return (last_node);
}

void	list_add_back(t_dlist **list, int n)
{
	t_dlist	*new_node;
	t_dlist	*last;

	if (list)
	{
		last = last_node(*list);
		new_node = create_node(n);
		new_node->next = *list;
		new_node->prev = last;
		last->next = new_node;
		(*list)->prev = last->next;
//		*list = new_node;  
	}
}

void	print_stack(t_dlist *list, t_dlist *list2)
{
	int		value;
	int		value2;
	t_dlist	*next;
	t_dlist	*temp;

	value = list->value;
	value2 = list2->value;
	next = list->next;
	temp = list2->next;
	ft_printf("list 1\t\tlist 2\n");
	ft_printf("%d\t\t%d\n", value, value2);
	while (value != next->value && value2 != temp->value)
	{
		printf("%d\t\t%d\n", next->value, temp->value);
		next = next->next;
		temp = temp->next;
	}
}

void	stack_fill(t_dlist **stack, char **argv)
{
	int	pos;
	int	val;

	pos = 0;
	*stack = create_node(ft_atoi_pos(argv[1], &pos));
	if (argv[1][pos] == ' ')
		pos++;
	while (argv[1][pos])
	{
		val = ft_atoi_pos(argv[1], &pos);
		list_add_back(stack, val);
		if (argv[1][pos] == ' ')
			pos++;
	}
}

/*void	del_node(t_dlist **stack)
{
	(*stack)->prev->next = (*stack)->next;
	(*stack)->next->prev = (*stack)->prev;
}*/
