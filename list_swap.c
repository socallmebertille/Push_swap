/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:23:05 by saberton          #+#    #+#             */
/*   Updated: 2024/09/06 15:45:26 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list_node **a)
{
	*a = (*a)->next;
	(*a)->previous->previous = *a;
	(*a)->previous->next = (*a)->next;
	if ((*a)->next)
		(*a)->next->previous = (*a)->previous;
	(*a)->next = (*a)->previous;
	(*a)->previous = NULL;
}

void	sa(t_list_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_list_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_list_node **a, t_list_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
