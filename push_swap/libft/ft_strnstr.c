/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowaidat <mowaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 23:33:39 by mowaidat          #+#    #+#             */
/*   Updated: 2025/12/15 23:33:42 by mowaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *sea, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*sea)
		return ((char *)src);
	while (i < n && src[i])
	{
		j = 0;
		while (i + j < n && src[i + j] && src[i + j] == sea[j])
			j++;
		if (!sea[j])
			return ((char *)(src + i));
		i++;
	}
	return (NULL);
}
