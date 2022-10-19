/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:37:13 by enolbas           #+#    #+#             */
/*   Updated: 2022/06/28 19:04:37 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s, int status)
{
	int		val;
	size_t	order;

	if (!s->first || !s->first->next)
		return ;
	val = s->first->next->val;
	order = s->first->next->order;
	del_one(s, val);
	add_first(s, create(val));
	s->first->order = order;
	if (status == 1)
		write(1, "sa", 2);
	else if (!status)
		write(1, "sb", 2);
	else
		return ;
	write(1, "\n", 1);
}

void	swap_ss(t_stack *a, t_stack *b)
{
	swap(a, 2);
	swap(b, 2);
}
