/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowaidat <mowaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:06:50 by mowaidat          #+#    #+#             */
/*   Updated: 2026/02/06 21:00:16 by mowaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
/*
 *  if insert just 3 number this is all cases
 * Case 1: 1 2 3 (already sorted)
 * Case 2: 1 3 2
 * Case 3: 2 1 3
 * Case 4: 2 3 1
 * Case 5: 3 1 2
 * Case 6: 3 2 1
 */
static int	get_values(t_stack *a, int *first, int *second, int *third)
{
	if (!a || !a->top || !a->top->next || !a->top->next->next)
		return (0);
	*first = a->top->value;
	*second = a->top->next->value;
	*third = a->top->next->next->value;
	return (1);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (!get_values(a, &first, &second, &third))
		return ;
	if (first < second && second < third)
		return ;
	if (first < second && second > third && first < third)
	{
		rra(a);
		swap_a(a);
	}
	else if (first > second && second < third && first < third)
		swap_a(a);
	else if (first < second && second > third && first > third)
		rra(a);
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first > second && second > third)
	{
		swap_a(a);
		rra(a);
	}
}
