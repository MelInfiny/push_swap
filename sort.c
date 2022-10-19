/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:33:55 by enolbas           #+#    #+#             */
/*   Updated: 2022/06/30 22:09:54 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_cent(t_stack *a, t_stack *b)
{
	if (a->size <= 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
	else
	{
		if (a->size < 30)
			rec_sort(a, b, 0, a->size / 3);
		else if (a->size <= 100)
			rec_sort(a, b, 0, a->size / 5);
		else
			rec_sort(a, b, 0, a->size / 11);
		while (b->first)
			insert_big(a, b);
	}
}

int	rec_sort(t_stack *a, t_stack *b, size_t start, int range)
{
	size_t	end;

	if (start >= a->size)
		return (1);
	end = start + range;
	if (end > a->size)
		end = a->size;
	if (choose_move(a, b, start, end))
		return (rec_sort(a, b, start, range));
	return (rec_sort(a, b, end, range));
}

int	sort_three(t_stack *s)
{
	t_elem	*one;
	size_t	max;

	one = s->first;
	max = find_max_order(s);
	if (is_sorted(s))
		return (1);
	if (one->order == max)
		rotate(s, 1);
	else if (one->next->order == max)
		rrotate(s, 1);
	else
		swap(s, 1);
	return (sort_three(s));
}

void	sort_five(t_stack *a, t_stack *b)
{
	size_t	size;

	size = a->size;
	if (size == 2)
	{
		swap(a, 1);
		return ;
	}
	while (size -- > 3)
		insert_min(a, b, size + 1);
	sort_three(a);
	while (b->first)
		push_a(a, b, 1);
}
