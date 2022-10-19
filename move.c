/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:40:43 by enolbas           #+#    #+#             */
/*   Updated: 2022/06/30 20:52:52 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choose_move(t_stack *s, t_stack *b, int start, size_t end)
{
	size_t	first;
	size_t	second;
	size_t	size;

	size = get_size(s);
	first = find_number(s, start, end);
	if (get_numbers(s, start, end) == 1)
	{
		move_top(s, first, size, 1);
		compare_order(s, b);
	}
	else if (get_numbers(s, start, end) > 1)
	{
		second = find_number_rr(s, start, end, size);
		if (find_moves(s, first, size) < find_moves(s, second, size))
			move_top(s, first, size, 1);
		else
			move_top(s, second, size, 1);
		compare_order(s, b);
		return (1);
	}
	return (0);
}

void	move_top(t_stack *s, size_t order, size_t size, int status)
{
	int	med;
	int	pos;

	med = find_median(size);
	pos = find_position(s, order);
	if (pos < med)
	{
		while (pos --)
			rotate(s, status);
	}
	else
	{
		while ((size_t) pos ++ != size)
			rrotate(s, status);
	}
}

int	find_number(t_stack *s, size_t start, size_t end)
{
	t_elem	*one;

	one = s->first;
	while (one)
	{
		if (one->order < end && one->order >= start)
			break ;
		one = one->next;
	}
	return (one->order);
}

int	find_number_rr(t_stack *s, size_t start, size_t end, size_t size)
{
	t_elem	*one;

	one = find_last(s, size);
	while (one->order != s->first->order)
	{
		if (one->order < end && one->order >= start)
			break ;
		one = find_last(s, --size);
	}
	return (one->order);
}
