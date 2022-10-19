/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:40:30 by enolbas           #+#    #+#             */
/*   Updated: 2022/06/28 19:40:32 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*poll_last(t_stack *s)
{
	t_elem	*one;

	if (!s)
		return (NULL);
	one = s->first;
	while (one->next)
		one = one->next;
	return (one);
}

t_elem	*poll_first(t_stack *s)
{
	t_elem	*one;

	if (!s)
		return (NULL);
	one = s->first;
	return (one);
}
