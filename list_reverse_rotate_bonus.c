/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_reverse_rotate_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 04:37:59 by saberton          #+#    #+#             */
/*   Updated: 2024/09/11 19:03:49 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	reverse_rotate(t_list **a)
{
	t_list	*last;

	last = ft_lstlast(*a);
	if (last == *a)
		return ;
	last->previous->next = NULL;
	last->next = *a;
	last->previous = NULL;
	*a = last;
	last->next->previous = last;
}

int	rra(t_list **a)
{
	reverse_rotate(a);
	return (0);
}

int	rrb(t_list **b)
{
	reverse_rotate(b);
	return (0);
}

int	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	return (0);
}
