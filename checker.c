/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:25:45 by enolbas           #+#    #+#             */
/*   Updated: 2022/09/01 17:48:38 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_str(int status)
{
	if (status)
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
	write(1, "\n", 1);
}

int	equals(char *line1, char *line2)
{
	int	r;
	int	status;

	r = 0;
	status = 1;
	while (line1[r])
	{
		if (line1[r] != line2[r])
			status = 0;
		r++;
	}
	if (line2[r] != '\0')
		status = 0;
	return (status);
}

int	stack_line(t_stack *a, t_stack *b, char *line)
{
	if (equals(line, "ra"))
		rotate(a, 2);
	else if (equals(line, "rb"))
		rotate(b, 2);
	else if (equals(line, "rr"))
		rotate_ss(a, b);
	else if (equals(line, "sa"))
		swap(a, 2);
	else if (equals(line, "sb"))
		swap(b, 2);
	else if (equals(line, "ss"))
		swap_ss(a, b);
	else if (equals(line, "rra"))
		rrotate(a, 2);
	else if (equals(line, "rrb"))
		rrotate(b, 2);
	else if (equals(line, "rrr"))
		rrotate_ss(a, b);
	else if (equals(line, "pa"))
		push_a(a, b, 0);
	else if (equals(line, "pb"))
		push_b(a, b, 0);
	else
		return (0);
	return (1);
}

int	read_stack(t_stack *a)
{
	t_stack	*b;
	int		r;
	int		count;
	char	line[BUFFER];

	b = stack_init();
	r = read(0, line, BUFFER);
	while (r)
	{
		count = 0;
		while (line[count] != '\n' && count < BUFFER)
			count ++;
		line[count] = '\0';
		if (!stack_line(a, b, line))
			print_error(a, b);
		r = read(0, line, BUFFER);
	}
	if (!b->first && is_sorted(a))
		print_str(1);
	else
		print_str(0);
	del_all(b);
	return (0);
}

int	main(int ac, char **argv)
{
	t_stack	*a;
	int		val;
	int		r;

	if (ac < 2)
		return (0);
	a = stack_init();
	while (ac-- > 1)
	{
		val = check_int(argv[ac], &r);
		if ((r == -1 && val == 0) || (r == 0) || !check_doublons(a, val))
			print_error(a, NULL);
		else
			add_first(a, create(val));
	}
	read_stack(a);
	del_all(a);
	return (0);
}
