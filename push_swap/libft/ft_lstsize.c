/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowaidat <mowaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 23:47:23 by mowaidat          #+#    #+#             */
/*   Updated: 2025/12/15 23:47:35 by mowaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*last;
	int		i;

	i = 0;
	last = lst;
	while (last != NULL)
	{
		i++;
		last = last->next;
	}
	return (i);
}
