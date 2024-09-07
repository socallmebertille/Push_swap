/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:54:30 by saberton          #+#    #+#             */
/*   Updated: 2024/09/07 08:58:28 by saberton         ###   ########.fr       */
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
		// pos_and_med(*a);
		// pos_and_med(*b);
		init_algo(*a, *b);
	}
	else if (!(cheapest->mediane) && !(cheapest->target->mediane))
	{
		while (cheapest != *b && cheapest->target != *a)
			rrr(a, b);
		// pos_and_med(*a);
		// pos_and_med(*b);
		init_algo(*a, *b);
	}
	sort_a_and_b(a, b, cheapest);
	pa(a, b);
}

static void	pre_sort(t_list_node **a, t_list_node **b)
{
	int			mid;
	int			med;

	med = (find_biggest_node(*a)->nb - find_lowest_node(*a)->nb) / 2;
	mid = count_node(*a) / 2;
	// if (count_node(*a) <= 3 || med <= 0)
	// 	return ;
	while (mid > 0)
	{
		if ((*a)->nb <= med)
		{
			mid--;
			med = (find_biggest_node(*a)->nb - find_lowest_node(*a)->nb) / 2;
			pb(a, b);
		}
		else // if ((*a)->nb > med && )
			ra(a);
	}
	return ;
	// if ((*a)->nb < med)
	// 	pb(a, b);
	// else
	// 	ra(a);
}

void	push_algo(t_list_node **a, t_list_node **b)
{
	t_list_node	*lower;
	// int			mid;

	// mid = count_node(*a) / 2;
	// while (mid-- > 0)
	// {
	// 	if ((*a)->nb <= mid)
	// 	{
	// 		mid = count_node(*a) / 2;
	// 		pb(a, b);
	// 	}
	// 	else
	// 		rra(a);
	// }
	while (count_node(*a) > 3)
		pre_sort(a, b);
	// while (count_node(*a) > 3)
	// 	pb(a, b);
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
