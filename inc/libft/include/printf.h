/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:00:07 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/09/02 15:15:24 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H

# include "libft.h"
# include <stdarg.h>

int			ft_printf(const char *str, ...);
size_t		printf_char(char c);
size_t		printf_str(char *str);
size_t		printf_ptr(unsigned long lnum);
size_t		printf_integer(int num);
size_t		printf_unsigned(unsigned int unum);
size_t		printf_hex(unsigned int num, const char format);

char		*ft_utoa(unsigned int num);

#endif
