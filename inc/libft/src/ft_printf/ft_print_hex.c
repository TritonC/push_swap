/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:00:13 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/09/02 15:19:11 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/* Function that returns a lenght of a hex variable. */
static size_t	ft_hexlen(unsigned int num)
{
	size_t	len;

	len = 0;
	while (num > 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

/* Recursive function that prints a hex variable. */
static void	ft_puthex_fd(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_puthex_fd(num / 16, format);
		ft_puthex_fd(num % 16, format);
	}
	else
	{
		if (num >= 10)
			printf_char((num - 10) + format);
		else
			printf_char(num + '0');
	}
}

/* Function that prints a hex variable and returns a length. */
size_t	printf_hex(unsigned int num, const char format)
{
	size_t	len;

	len = 0;
	if (num == 0)
		len = write(1, "0", 1);
	else
	{
		if (format == 'x')
			ft_puthex_fd(num, 'a');
		else if (format == 'X')
			ft_puthex_fd(num, 'A');
		len = ft_hexlen(num);
	}
	return (len);
}
