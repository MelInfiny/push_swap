/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:39:51 by enolbas           #+#    #+#             */
/*   Updated: 2022/09/01 17:25:37 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_char(char c)
{
	write(1, &c, 1);
}

void	print_nbr(int n)
{
	long int	nbr;

	if (n < 0)
	{
		nbr = (long int) n * (-1);
		print_char('-');
	}
	else
		nbr = (long int) n;
	if (nbr > 9)
		print_nbr(nbr / 10);
	nbr %= 10;
	print_char('0' + nbr);
}

void	print_stack(t_stack *s)
{
	t_elem	*one;

	one = s->first;
	while (one)
	{
		print_nbr(one->val);
		print_char(' ');
		one = one->next;
	}
	print_char('\n');
}

void	print_order(t_stack *s)
{
	t_elem	*one;

	one = s->first;
	while (one)
	{
		print_nbr(one->order);
		print_char(' ');
		one = one->next;
	}
	print_char('\n');
}

int	main(int ac, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = check_input(ac, argv);
	if (!a)
		return (0);
	a->size = get_size(a);
	set_order(a, 0, -2147483649);
	if (!is_sorted(a))
	{
		b = stack_init();
		radix_cent(a, b);
		del_all(b);
	}
	del_all(a);
	return (0);
}
