/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:35:10 by enolbas           #+#    #+#             */
/*   Updated: 2022/06/30 21:06:54 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_all(t_stack *s)
{
	t_elem	*one;

	if (!s)
		return ;
	while (s->first)
	{
		one = s->first;
		s->first = one->next;
		free(one);
	}
	free(s);
}

void	del_first(t_stack *s)
{
	t_elem	*one;

	if (!s)
		return ;
	one = s->first;
	s->first = one->next;
	free(one);
}

void	del_last(t_stack *s)
{
	t_elem	*one;

	if (!s)
		return ;
	if (get_size(s) == 1)
	{
		free(s->first);
		s->first = NULL;
		return ;
	}
	one = s->first;
	while (one->next->next != NULL)
		one = one->next;
	free(one->next);
	one->next = NULL;
}

void	del_one(t_stack *s, int val)
{
	t_elem	*tmp;
	t_elem	*curr;

	tmp = s->first;
	if (!s)
		return ;
	while (tmp->next && tmp->next->val != val)
	{
		tmp = tmp->next;
	}
	if (tmp->next->val == val)
	{
		curr = tmp->next;
		tmp->next = curr->next;
		free(curr);
	}
}

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
