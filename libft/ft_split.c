/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucorrei <lucorrei@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:43:36 by lucorrei          #+#    #+#             */
/*   Updated: 2025/04/15 12:10:16 by lucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	_count_words(const char *s, char c)
{
	int		is_word;
	int		word_count;

	word_count = 0;
	is_word = 0;
	while (1)
	{
		if (*s != c && !is_word)
			is_word = 1;
		else if ((*s == c || !*s) && is_word)
		{
			is_word = 0;
			word_count++;
		}
		if (!*s)
			break ;
		s++;
	}
	return (word_count);
}

static char	**_free_str_arr(char ***arr, int nelm)
{
	int		i;
	char	**res;

	res = *arr;
	i = -1;
	while (++i < nelm + 1)
		free(res[i]);
	free(res);
	res = NULL;
	return (res);
}

static char	**_copy_words(const char *s, char c, char ***res, int max)
{
	int		is_word;
	int		word_count;
	char	*beg;

	word_count = 0;
	is_word = 0;
	beg = 0;
	while (word_count < max)
	{
		if (*s != c && !is_word)
		{
			is_word = 1;
			beg = (char *)s;
		}
		else if ((*s == c || !*s) && is_word)
		{
			is_word = 0;
			(*res)[word_count] = ft_calloc(s - beg + 1, 1);
			if (!(*res)[word_count])
				return (_free_str_arr(res, max));
			ft_strlcpy((*res)[word_count++], beg, s - beg + 1);
		}
		s++;
	}
	return (*res);
}

char	**ft_split(char const *s, char c)
{
	int		max;
	char	**res;

	max = _count_words(s, c);
	res = 0;
	res = ft_calloc(max + 1, sizeof(char *));
	if (!res)
		return (NULL);
	return (_copy_words(s, c, &res, max));
}
