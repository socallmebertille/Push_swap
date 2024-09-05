/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:55:00 by saberton          #+#    #+#             */
/*   Updated: 2024/09/05 18:14:52 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pos_and_med(t_list_node *a)
{
	int	i;
	int	med;

	i = 0;
	med = count_node(a) / 2;
	if (a == NULL)
		return ;
	while (a)
	{
		a->position = i;
		if (i <= med)
			a->mediane = true;
		else
			a->mediane = false;
		a = a->next;
		i++;
	}
	return ;
}

void	find_target(t_list_node *a, t_list_node *b)
{
	long		i;
	t_list_node	*begin;

	i = LONG_MAX;
	while (b)
	{
		i = LONG_MAX;
		begin = a;
		while (begin)
		{
			if (begin->nb > b->nb && begin->nb < i)
			{
				b->target = begin;
				i = begin->nb;
			}
			begin = begin->next;
		}
		if (i == LONG_MAX)
			b->target = find_lowest_node(a);
		b = b->next;
	}
	return ;
}

void	find_cost(t_list_node *a, t_list_node *b)
{
	while (b)
	{
		b->cost = b->position;
		if (b->mediane == false)
			b->cost = count_node(b) - b->position;
		if (b->target->mediane == true)
			b->cost += b->target->position;
		else
			b->cost += count_node(a) - b->target->position;
		b = b->next;
	}
	return ;
}

void	find_cheapest(t_list_node *b)
{
	t_list_node	*cheapest;
	int			i;

	cheapest = NULL;
	i = INT_MAX;
	while (b)
	{
		if (b->cost < i)
		{
			cheapest = b;
			i = b->cost;
		}
		b = b->next;
	}
	cheapest->cheapest = true;
	return ;
}

void	init_algo(t_list_node *a, t_list_node *b)
{
	pos_and_med(a);
	pos_and_med(b);
	find_target(a, b);
	find_cost(a, b);
	find_cheapest(b);
}