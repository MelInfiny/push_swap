/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:30:59 by enolbas           #+#    #+#             */
/*   Updated: 2022/06/30 20:46:20 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(*stack));
	if (!stack)
		return (NULL);
	stack->first = NULL;
	stack->size = 0;
	return (stack);
}

t_elem	*create(int val)
{
	t_elem	*one;

	one = malloc(sizeof(*one));
	if (!one)
		return (NULL);
	one->val = val;
	one->order = 0;
	one->next = NULL;
	return (one);
}

void	add_first(t_stack *s, t_elem *one)
{
	if (!s->first)
	{
		s->first = one;
	}
	else
	{
		one->next = s->first;
		s->first = one;
	}
}

void	add_last(t_stack *s, t_elem *one)
{
	t_elem	*tmp;

	if (!s->first)
	{
		s->first = one;
	}
	else
	{
		tmp = s->first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = one;
	}
}

size_t	get_size(t_stack *s)
{
	size_t	count;
	t_elem	*one;

	count = 0;
	if (!s)
		return (0);
	one = s->first;
	while (one)
	{
		count ++;
		one = one->next;
	}
	return (count);
}
