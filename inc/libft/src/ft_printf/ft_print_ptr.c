/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 01:27:07 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/09/03 01:27:09 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*  Function that returns the length of a pointer variable. */
static size_t	ft_ptrlen(unsigned long lnum)
{
	size_t	len;

	len = 0;
	while (lnum > 0)
	{
		lnum /= 16;
		len++;
	}
	return (len);
}

/* Recursive function that prints a pointer variable. */
static void	ft_putptr_fd(unsigned long lnum)
{
	if (lnum >= 16)
	{
		ft_putptr_fd(lnum / 16);
		ft_putptr_fd(lnum % 16);
	}
	else
	{
		if (lnum >= 10)
			printf_char((lnum - 10) + 'a');
		else
			printf_char(lnum + '0');
	}
}

/* Function that prints a pointer variable and returns a length. */
size_t	printf_ptr(unsigned long ptr)
{
	size_t	len;

	len = write(1, "0x", 2);
	if (ptr == 0)
		len += write(1, "0", 1);
	else
	{
		len += ft_ptrlen(ptr);
		ft_putptr_fd(ptr);
	}	
	return (len);
}
