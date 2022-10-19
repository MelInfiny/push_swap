/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:27:58 by enolbas           #+#    #+#             */
/*   Updated: 2022/06/30 22:55:40 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_moves(t_stack *s, size_t order, size_t size)
{
	int	pos;
	int	med;

	med = find_median(size);
	pos = find_position(s, order);
	if (pos != -1 && pos < med)
		return (pos);
	return (size - pos);
}

int	find_position(t_stack *s, size_t order)
{
	size_t	count;
	t_elem	*one;

	count = 0;
	one = s->first;
	while (one && one->order != order)
	{
		one = one->next;
		count++;
	}
	if (one->order == order)
		return (count);
	return (-1);
}

int	find_median(size_t size)
{
	int	med;

	if (size % 2 == 0)
		med = size / 2;
	else
		med = (size + 1) / 2;
	return (med);
}

int	get_numbers(t_stack *s, int start, int end)
{
	int		count;
	t_elem	*one;

	count = 0;
	one = s->first;
	while (one)
	{
		if (one->order >= (size_t) start && one->order < (size_t) end)
			count ++;
		one = one->next;
	}
	return (count);
}
