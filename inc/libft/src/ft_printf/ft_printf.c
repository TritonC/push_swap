/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:00:25 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/09/02 15:28:36 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/* Function that evaluate the flags from printf. */
int	printf_format(char format, va_list arguments)
{
	size_t	len;

	len = 0;
	if (format == 'c')
		len = printf_char(va_arg(arguments, int));
	else if (format == 's')
		len = printf_str(va_arg(arguments, char *));
	else if (format == 'p')
		len = printf_ptr(va_arg(arguments, unsigned long));
	else if (format == 'd' || format == 'i')
		len = printf_integer(va_arg(arguments, int));
	else if (format == 'u')
		len = printf_unsigned(va_arg(arguments, unsigned int));
	else if (format == 'x' || format == 'X')
		len = printf_hex(va_arg(arguments, unsigned int), format);
	else if (format == '%')
		len = printf_char('%');
	else
		len = printf_char(format);
	return (len);
}

/* Function printf. */
int	ft_printf(const char *str, ...)
{
	size_t		i;
	int			length;
	va_list		args;

	va_start(args, str);
	i = 0;
	length = 0;
	while (*(str + i))
	{
		if (*(str + i) == '%')
		{
			i++;
			length += printf_format(*(str + i), args);
		}
		else
			length += write(1, (str + i), 1);
		i++;
	}
	va_end(args);
	return (length);
}
