/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:32:40 by enolbas           #+#    #+#             */
/*   Updated: 2022/06/30 19:47:53 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_min(t_stack *a, t_stack *b, size_t size)
{
	int	min;
	int	med;

	med = find_median(size);
	min = find_position(a, find_min_order(a));
	if (min < med && min != -1)
	{
		while (min --)
			rotate(a, 1);
	}
	else
	{
		while ((size_t) min++ < size)
			rrotate(a, 1);
	}
	push_b(a, b, 1);
}

void	insert_big(t_stack *a, t_stack *b)
{
	int	max;

	max = find_max_order(b);
	move_top(b, max, get_size(b), 0);
	push_a(a, b, 1);
}

void	compare_order(t_stack *a, t_stack *b)
{
	push_b(a, b, 1);
	if (b->first->next && b->first->order < b->first->next->order)
		swap(b, 0);
}
