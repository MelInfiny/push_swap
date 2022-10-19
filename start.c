/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:40:58 by enolbas           #+#    #+#             */
/*   Updated: 2022/06/28 19:41:00 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*find_last(t_stack *s, size_t pos)
{
	t_elem	*one;
	size_t	p;

	one = s->first;
	p = 0;
	while (one && p != pos - 1)
	{
		one = one->next;
		p ++;
	}
	return (one);
}
