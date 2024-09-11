/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 04:38:26 by saberton          #+#    #+#             */
/*   Updated: 2024/09/11 19:03:32 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	push(t_list **a, t_list **b)
{
	t_list	*push_node;

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

int	pa(t_list **a, t_list **b)
{
	push(b, a);
	return (0);
}

int	pb(t_list **a, t_list **b)
{
	push(a, b);
	return (0);
}
