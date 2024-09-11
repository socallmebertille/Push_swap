/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rotate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 04:37:24 by saberton          #+#    #+#             */
/*   Updated: 2024/09/11 19:04:15 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	rotate(t_list **a)
{
	t_list	*last;

	last = ft_lstlast(*a);
	last->next = (*a);
	*a = (*a)->next;
	(*a)->previous = NULL;
	last->next->previous = last;
	last->next->next = NULL;
}

int	ra(t_list **a)
{
	rotate(a);
	return (0);
}

int	rb(t_list **b)
{
	rotate(b);
	return (0);
}

int	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	return (0);
}
