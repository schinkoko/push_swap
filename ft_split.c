/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 18:06:05 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/06/20 13:44:31 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_args.h"

static size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	wc;
	int		in_word;

	i = 0;
	wc = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && !in_word)
		{
			in_word = 1;
			++wc;
		}
		if (s[i] == c)
			in_word = 0;
		++i;
	}
	return (wc);
}

static char	*alloc(size_t word_len, char const *s)
{
	char	*word;
	size_t	i;

	i = 0;
	word = malloc(word_len + 1);
	if (!word)
		return (NULL);
	while (word_len--)
		word[i++] = *s++;
	word[i] = '\0';
	return (word);
}

static void	free_all(char **arr, size_t idx)
{
	size_t	i;

	i = 0;
	if (!arr)
		return ;
	arr[idx] = NULL;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static int	iter_and_word_len(char const **s, char c)
{
	size_t	word_len;

	word_len = 0;
	while (**s && **s == c)
		++(*s);
	while ((*s)[word_len] && (*s)[word_len] != c)
		++word_len;
	return (word_len);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	word_len;
	size_t	i;

	i = 0;
	arr = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (*s)
	{
		word_len = iter_and_word_len(&s, c);
		if (word_len)
		{
			arr[i] = alloc(word_len, s);
			if (!arr[i])
				return (free_all(arr, i), NULL);
			s += word_len;
			++i;
		}
	}
	arr[i] = NULL;
	return (arr);
}
