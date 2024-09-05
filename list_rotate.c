/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:55:13 by saberton          #+#    #+#             */
/*   Updated: 2024/09/05 18:14:58 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list_node **a)
{
	t_list_node	*last;

	last = find_last(*a);
	last->next = (*a);
	*a = (*a)->next;
	(*a)->previous = NULL;
	last->next->previous = last;
	last->next->next = NULL;
}
void	ra(t_list_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_list_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_list_node **a, t_list_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}