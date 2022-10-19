/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:32:16 by enolbas           #+#    #+#             */
/*   Updated: 2022/06/30 22:56:48 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *a, t_stack *b, int status)
{
	int	val;

	if (!b->first)
		return ;
	val = b->first->val;
	add_first(a, create(val));
	a->first->order = b->first->order;
	del_first(b);
	if (status)
	{
		write(1, "pa", 2);
		write(1, "\n", 1);
	}
}

void	push_b(t_stack *a, t_stack *b, int status)
{
	int	val;

	if (!a->first)
		return ;
	val = a->first->val;
	add_first(b, create(val));
	b->first->order = a->first->order;
	del_first(a);
	if (status)
	{
		write(1, "pb", 2);
		write(1, "\n", 1);
	}
}
