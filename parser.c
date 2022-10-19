/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:25:45 by enolbas           #+#    #+#             */
/*   Updated: 2022/09/01 17:47:51 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s)
{
	t_elem	*one;

	one = s->first;
	while (one->next)
	{
		if (one->next->val < one->val)
			return (0);
		one = one->next;
	}
	return (1);
}

void	print_error(t_stack *a, t_stack *b)
{
	write(2, "Error\n", 6);
	if (a)
		del_all(a);
	if (b)
		del_all(b);
	exit (0);
}

int	check_int(char *s, int *sign)
{
	int		count;
	long	num;

	count = 0;
	*sign = 1;
	num = 0;
	if (s[count] == 32 || (s[count] >= 9 && s[count] <= 13))
		count++;
	if (s[count] == '+' || s[count] == '-')
	{
		if (s[count] == '-')
			*sign *= -1;
		count++;
	}
	while (s[count])
	{
		num = (num * 10) + s[count] - 48;
		if (num * *sign > 2147483647 || num * *sign < -2147483648
			|| s[count] < '0' || s[count] > '9')
			*sign = 0;
		count++;
	}
	return (num * *sign);
}

int	check_doublons(t_stack *s, int x)
{
	t_elem	*one;

	one = s->first;
	while (one)
	{
		if (one->val == x)
			return (0);
		one = one->next;
	}
	return (1);
}

t_stack	*check_input(int ac, char **argv)
{
	t_stack	*a;
	int		val;
	int		r;

	if (ac < 2)
		return (NULL);
	a = stack_init();
	while (ac-- > 1)
	{
		val = check_int(argv[ac], &r);
		if ((r == -1 && val == 0) || (r == 0) || !check_doublons(a, val))
			print_error(a, NULL);
		else
			add_first(a, create(val));
	}
	return (a);
}
