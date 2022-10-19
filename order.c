/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:28:13 by enolbas           #+#    #+#             */
/*   Updated: 2022/06/28 19:21:29 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_order(t_stack *s, int count, long min)
{
	int		new_min;
	t_elem	*one;

	one = s->first;
	new_min = find_min(s, min);
	if (min == new_min)
		return (1);
	while (one && one->val != new_min)
		one = one->next;
	if (one->val == new_min)
		one->order = count;
	return (set_order(s, ++count, new_min));
}

int	find_min(t_stack *s, long prec)
{
	t_elem	*one;
	int		min;

	one = s->first;
	min = find_max(s);
	while (one)
	{
		if (one->val < min && one->val > prec)
			min = one->val;
		one = one->next;
	}
	return (min);
}

int	find_max(t_stack *s)
{
	t_elem	*one;
	int		max;

	one = s->first;
	max = one->val;
	while (one)
	{
		if (one->val > max)
			max = one->val;
		one = one->next;
	}
	return (max);
}

size_t	find_min_order(t_stack *s)
{
	t_elem	*one;
	size_t	min;

	one = s->first;
	min = one->order;
	while (one)
	{
		if (one->order < min)
			min = one->order;
		one = one->next;
	}
	return (min);
}

size_t	find_max_order(t_stack *s)
{
	t_elem	*one;
	size_t	max;

	one = s->first;
	max = 0;
	while (one)
	{
		if (one->order > max)
			max = one->order;
		one = one->next;
	}
	return (max);
}
