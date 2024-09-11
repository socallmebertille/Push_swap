/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:52:59 by saberton          #+#    #+#             */
/*   Updated: 2024/09/11 19:00:44 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_node_sort(t_list **a)
{
	t_list	*biggest;

	biggest = find_biggest(*a);
	if (biggest == *a)
		ra(a);
	else if (biggest == (*a)->next)
		rra(a);
	if ((*a)->nb > (*a)->next->nb)
		sa(a);
}

static void	sort_a_and_b(t_list **a, t_list **b,
		t_list *cheapest)
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

static void	replace_in_a(t_list **a, t_list **b)
{
	t_list	*cheapest;

	cheapest = *b;
	while (cheapest)
	{
		if (cheapest->cheapest == true)
			break ;
		cheapest = cheapest->next;
	}
	if (cheapest->mediane == true && cheapest->target->mediane == true)
	{
		while (cheapest != *b && cheapest->target != *a)
			rr(a, b);
		init_algo(*a, *b);
	}
	else if (!(cheapest->mediane) && !(cheapest->target->mediane))
	{
		while (cheapest != *b && cheapest->target != *a)
			rrr(a, b);
		init_algo(*a, *b);
	}
	sort_a_and_b(a, b, cheapest);
	pa(a, b);
}

static void	push_algo(t_list **a, t_list **b)
{
	t_list	*smallest;

	while (count_node(*a) > 3)
		mediane_a_to_b(a, b);
	three_node_sort(a);
	while (*b)
	{
		init_algo(*a, *b);
		replace_in_a(a, b);
	}
	init_algo(*a, *b);
	smallest = find_smallest(*a);
	if (smallest->mediane == true)
	{
		while (smallest != *a)
			ra(a);
	}
	else
	{
		while (smallest != *a)
			rra(a);
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || !av[1][0])
		return (EXIT_FAILURE);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (av == NULL)
			exit(EXIT_FAILURE);
	}
	checks_and_list(av + 1, ac == 2, &a);
	if (!in_order(a))
	{
		if (count_node(a) == 2)
			sa(&a);
		else if (count_node(a) == 3)
			three_node_sort(&a);
		else
			push_algo(&a, &b);
	}
	free_list(&a);
	return (0);
}
