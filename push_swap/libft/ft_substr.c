/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowaidat <mowaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 23:37:19 by mowaidat          #+#    #+#             */
/*   Updated: 2025/12/15 23:37:25 by mowaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_output(char const *s, unsigned int start, size_t l)
{
	size_t	len_s;
	size_t	alive;

	len_s = ft_strlen(s);
	if (start >= len_s)
		return (0);
	alive = len_s - start;
	if (l < alive)
		return (l);
	return (alive);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_o;
	size_t	i;
	char	*output;

	if (s == NULL)
		return (NULL);
	len_o = len_output(s, start, len);
	output = (char *)malloc(len_o + 1);
	if (output == NULL)
		return (NULL);
	i = 0;
	while (i < len_o)
	{
		output[i] = s[start + i];
		i++;
	}
	output[len_o] = '\0';
	return (output);
}
