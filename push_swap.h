/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:40:15 by enolbas           #+#    #+#             */
/*   Updated: 2022/09/01 17:49:02 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

# define BUFFER 4
/*****************************************************/
/*****			STRUCTURES		*****/
/***************************************************/

typedef struct s_elem
{
	int				val;
	size_t			order;
	struct s_elem	*next;
}					t_elem;

typedef struct s_stack
{
	t_elem	*first;
	size_t	size;
}			t_stack;

/*****************************************************/
/*****			FUNCTIONS		*****/
/***************************************************/

t_stack	*stack_init(void);
t_stack	*check_input(int ac, char **argv);

t_elem	*create(int val);
t_elem	*find_last(t_stack *s, size_t pos);

size_t	find_min_order(t_stack *s);
size_t	find_max_order(t_stack *s);
size_t	get_size(t_stack *s);

void	add_first(t_stack *s, t_elem *one);
void	add_last(t_stack *s, t_elem *one);
void	del_first(t_stack *s);
void	del_last(t_stack *s);
void	del_all(t_stack *s);
void	del_one(t_stack *s, int val);

void	print_stack(t_stack *s);
void	print_order(t_stack *s);
void	print_error(t_stack *a, t_stack *b);

void	swap(t_stack *s, int status);
void	swap_ss(t_stack *a, t_stack *b);
void	push_a(t_stack *a, t_stack *b, int status);
void	push_b(t_stack *a, t_stack *b, int status);
void	rotate(t_stack *s, int status);
void	rotate_ss(t_stack *a, t_stack *b);
void	rrotate(t_stack *s, int status);
void	rrotate_ss(t_stack *a, t_stack *b);

void	insert(t_stack *a, t_stack *b, size_t size);
void	insert_min(t_stack *a, t_stack *b, size_t size);
void	insert_big(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	move_top(t_stack *s, size_t order, size_t size, int status);
void	radix_cent(t_stack *a, t_stack *b);
void	compare_order(t_stack *a, t_stack *b);

int		choose_move(t_stack *a, t_stack *b, int start, size_t end);
int		rec_sort(t_stack *a, t_stack *b, size_t start, int range);
int		is_min_or_max(t_stack *s, size_t size);
int		find_moves(t_stack *s, size_t order, size_t size);
int		find_position(t_stack *s, size_t order);
int		find_number(t_stack *s, size_t start, size_t end);
int		find_number_rr(t_stack *s, size_t start, size_t end, size_t size);
int		find_min(t_stack *s, long prec);
int		find_max(t_stack *s);
int		find_median(size_t size);
int		sort_three(t_stack *s);
int		set_order(t_stack *s, int count, long min);
int		get_numbers(t_stack *s, int start, int end);

int		is_sorted(t_stack *s);
int		check_doublons(t_stack *s, int val);
int		check_int(char *input, int *r);

int		main(int ac, char **argv);
#endif
