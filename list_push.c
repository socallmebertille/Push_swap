/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:32:03 by saberton          #+#    #+#             */
/*   Updated: 2024/09/05 18:14:31 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list_node **a, t_list_node **b)
{
	t_list_node	*push_node;

	push_node = *a;
	if (*a == NULL)
		return ;
	*a = (*a)->next;
	if (*a)
		(*a)->previous = NULL;
	if (*b == NULL)
	{
		*b = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *b;
		push_node->next->previous = push_node;
		*b = push_node;
	}
}

void	pa(t_list_node **a, t_list_node **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_list_node **a, t_list_node **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
