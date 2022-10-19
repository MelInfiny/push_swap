/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:34:30 by enolbas           #+#    #+#             */
/*   Updated: 2022/06/28 19:05:21 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *s, int status)
{
	int	val;

	if (!s->first)
		return ;
	val = s->first->val;
	add_last(s, create(val));
	find_last(s, get_size(s))->order = s->first->order;
	del_first(s);
	if (status == 1)
		write(1, "ra", 2);
	else if (!status)
		write(1, "rb", 2);
	else
		return ;
	write(1, "\n", 1);
}

void	rrotate(t_stack *s, int status)
{
	t_elem	*one;

	if (!s->first)
		return ;
	one = find_last(s, get_size(s));
	add_first(s, create(one->val));
	s->first->order = one->order;
	del_last(s);
	if (status == 1)
		write(1, "rra", 3);
	else if (!status)
		write(1, "rrb", 3);
	else
		return ;
	write(1, "\n", 1);
}

void	rotate_ss(t_stack *a, t_stack *b)
{
	rotate(a, 2);
	rotate(b, 2);
}

void	rrotate_ss(t_stack *a, t_stack *b)
{
	rrotate(a, 2);
	rrotate(b, 2);
}
