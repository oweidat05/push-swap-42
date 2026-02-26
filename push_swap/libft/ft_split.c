/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowaidat <mowaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 23:26:57 by mowaidat          #+#    #+#             */
/*   Updated: 2025/12/17 14:42:29 by mowaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static char	**free_memory(char **array, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static char	**size_word_in_memory(char const *s, char c, char **array)
{
	int	i;
	int	j;
	int	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = i;
			while (s[j] && s[j] != c)
				j++;
			array[w] = malloc(sizeof(char) * (j - i + 1));
			if (!array[w])
				return (free_memory(array, w));
			w++;
			i = j;
		}
		else
			i++;
	}
	array[w] = NULL;
	return (array);
}

static char	**fill_array(char const *s, char c, char **array)
{
	int	i;
	int	w;
	int	a;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			a = 0;
			while (s[i] && s[i] != c)
				array[w][a++] = s[i++];
			array[w][a] = '\0';
			w++;
		}
		else
			i++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		w;

	if (!s)
		return (NULL);
	w = count_words(s, c);
	array = malloc(sizeof(char *) * (w + 1));
	if (!array)
		return (NULL);
	array = size_word_in_memory(s, c, array);
	if (!array)
		return (NULL);
	array = fill_array(s, c, array);
	return (array);
}
