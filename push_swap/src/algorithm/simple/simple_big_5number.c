/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_big_5number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowaidat <mowaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 21:03:11 by mowaidat          #+#    #+#             */
/*   Updated: 2026/02/06 22:27:51 by mowaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*cur;

	cur = a->top;
	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

static void	restore_stack(t_stack *a, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		rra(a);
		i++;
	}
}

static int	bubble_pass(t_stack *a, int len)
{
	int	i;
	int	did_swap;

	i = 0;
	did_swap = 0;
	while (i < len - 1)
	{
		if (a->top->value > a->top->next->value)
		{
			swap_a(a);
			did_swap = 1;
		}
		ra(a);
		i++;
	}
	restore_stack(a, len);
	return (did_swap);
}

void	bubble_sort(t_stack *a)
{
	int	len;
	int	did_swap;

	if (!a || a->size < 2)
		return ;
	len = a->size;
	while (!is_sorted(a))
	{
		did_swap = bubble_pass(a, len);
		if (!did_swap)
			break ;
		len--;
	}
}
