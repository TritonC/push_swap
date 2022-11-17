/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 02:09:09 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/09/02 15:23:02 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/* Function that returns a lenght of a unsigned int variable. */
static size_t	ft_unsignedlen(unsigned int num)
{
	size_t	len;

	len = 0;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	return (len + 1);
}

/* Function that return a string of a unsigned int variable. */
char	*ft_utoa(unsigned int num)
{
	char	*str;
	size_t	len;

	len = ft_unsignedlen(num);
	str = (char *) malloc(len * sizeof(char));
	if (str == NULL)
		return (NULL);
	*(str + len--) = 0;
	while (num >= 10)
	{
		*(str + len) = (num % 10) + '0';
		num /= 10;
		len--;
	}
	*(str + len) = (num % 10) + '0';
	return (str);
}

/* Function that print a unsigned int variable and returns the lenght.  */
size_t	printf_unsigned(unsigned int unum)
{
	char	*str_unum;
	size_t	len;

	len = 0;
	if (unum == 0)
		len = write(1, "0", 1);
	else
	{
		str_unum = ft_utoa(unum);
		len = printf_str(str_unum);
		free(str_unum);
	}
	return (len);
}

/* Function that print a int variable and returns the lenght.  */
size_t	printf_integer(int num)
{
	char	*str_num;
	size_t	len;

	len = 0;
	if (num == 0)
		len = write(1, "0", 1);
	else
	{
		str_num = ft_itoa(num);
		len = printf_str(str_num);
		free(str_num);
	}
	return (len);
}
