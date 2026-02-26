/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowaidat <mowaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 23:35:16 by mowaidat          #+#    #+#             */
/*   Updated: 2025/12/15 23:35:18 by mowaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	const char	*last = NULL;

	while (*src)
	{
		if (*src == (char)c)
			last = src;
		src++;
	}
	if ((char)c == '\0')
		return ((char *)src);
	return ((char *)last);
}
