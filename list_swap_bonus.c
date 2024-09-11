/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 04:36:06 by saberton          #+#    #+#             */
/*   Updated: 2024/09/11 19:04:28 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	swap(t_list **a)
{
	*a = (*a)->next;
	(*a)->previous->previous = *a;
	(*a)->previous->next = (*a)->next;
	if ((*a)->next)
		(*a)->next->previous = (*a)->previous;
	(*a)->next = (*a)->previous;
	(*a)->previous = NULL;
}

int	sa(t_list **a)
{
	swap(a);
	return (0);
}

int	sb(t_list **b)
{
	swap(b);
	return (0);
}

int	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	return (0);
}
