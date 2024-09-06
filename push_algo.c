/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:54:30 by saberton          #+#    #+#             */
/*   Updated: 2024/09/06 15:44:27 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list_node	*return_cheapest(t_list_node *b)
{
	while (b)
	{
		if (b->cheapest == true)
			return (b);
		b = b->next;
	}
	return (NULL);
}

static void	sort_a_and_b(t_list_node **a, t_list_node **b,
		t_list_node *cheapest)
{
	while (*b != cheapest)
	{
		if (cheapest->mediane == true)
			rb(b);
		else
			rrb(b);
	}
	while (*a != cheapest->target)
	{
		if (cheapest->target->mediane == true)
			ra(a);
		else
			rra(a);
	}
}

void	replace_in_a(t_list_node **a, t_list_node **b)
{
	t_list_node	*cheapest;

	cheapest = return_cheapest(*b);
	if (cheapest->mediane == true && cheapest->target->mediane == true)
	{
		while (cheapest != *b && cheapest->target != *a)
			rr(a, b);
		pos_and_med(*a);
		pos_and_med(*b);
	}
	else if (!(cheapest->mediane) && !(cheapest->target->mediane))
	{
		while (cheapest != *b && cheapest->target != *a)
			rrr(a, b);
		pos_and_med(*a);
		pos_and_med(*b);
	}
	sort_a_and_b(a, b, cheapest);
	pa(a, b);
}

void	push_algo(t_list_node **a, t_list_node **b)
{
	t_list_node	*lower;
	int			nb_node_a;

	nb_node_a = count_node(*a);
	while (nb_node_a-- > 3)
		pb(a, b);
	three_node_sort(a);
	while (*b)
	{
		init_algo(*a, *b);
		replace_in_a(a, b);
	}
	pos_and_med(*a);
	lower = find_lowest_node(*a);
	if (lower->mediane == true)
	{
		while (lower != *a)
			ra(a);
	}
	else
	{
		while (lower != *a)
			rra(a);
	}
}
