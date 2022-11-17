/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomes-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:58:06 by lgomes-o          #+#    #+#             */
/*   Updated: 2022/06/28 02:50:17 by lgomes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char d)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (*(str + i) != '\0')
	{
		while (*(str + i) == d)
			i++;
		if (*(str + i) != '\0')
			words++;
		while (*(str + i) != '\0' && *(str + i) != d)
			i++;
	}
	return (words);
}

static void	put_word(char *word, const char *str, size_t i, size_t size)
{
	size_t	iw;

	iw = 0;
	while (size > 0)
	{
		*(word + iw) = *(str + (i - size));
		iw++;
		size--;
	}
	*(word + iw) = '\0';
}

static char	**free_spl(char **spl, size_t wk)
{
	while (wk > 0)
	{
		wk--;
		free(*(spl + wk));
	}
	free(spl);
	return (NULL);
}

static char	**allocate_words(char **spl, const char *str, char d, size_t len)
{
	size_t		i;
	size_t		w_len;
	size_t		w_num;

	i = 0;
	w_len = 0;
	w_num = 0;
	while (w_num < len)
	{
		while (*(str + i) != '\0' && *(str + i) == d)
			i++;
		while (*(str + i) != '\0' && *(str + i) != d)
		{
			w_len++;
			i++;
		}
		*(spl + w_num) = (char *) malloc((w_len + 1) * sizeof(char));
		if (*(spl + w_num) == NULL)
			return (free_spl((char **)spl, w_num));
		put_word(*(spl + w_num), str, i, w_len);
		w_len = 0;
		w_num++;
	}
	*(spl + w_num) = NULL;
	return (spl);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	w;

	if (s == NULL)
		return (NULL);
	w = count_words(s, c);
	split = (char **) malloc((w + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	return (allocate_words(split, s, c, w));
}
