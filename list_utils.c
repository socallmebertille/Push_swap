/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:09:28 by saberton          #+#    #+#             */
/*   Updated: 2024/09/08 02:10:17 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	in_order(t_list *a)
{
	if (a == NULL)
		return (true);
	while (a->next)
	{
		if (a->nb > a->next->nb)
			return (false);
		a = a->next;
	}
	return (true);
}

int	count_node(t_list *a)
{
	int	count;

	if (a == NULL)
		return (0);
	count = 0;
	while (a)
	{
		a = a->next;
		count++;
	}
	return (count);
}

t_list	*find_biggest(t_list *a)
{
	t_list	*biggest;
	int		i;

	if (a == NULL)
		return (NULL);
	biggest = NULL;
	i = INT_MIN;
	while (a)
	{
		if (i < a->nb)
		{
			biggest = a;
			i = a->nb;
		}
		a = a->next;
	}
	return (biggest);
}

t_list	*find_smallest(t_list *a)
{
	t_list	*smallest;
	int		i;

	if (a == NULL)
		return (NULL);
	smallest = NULL;
	i = INT_MAX;
	while (a)
	{
		if (i > a->nb)
		{
			smallest = a;
			i = a->nb;
		}
		a = a->next;
	}
	return (smallest);
}

t_list	*find_last(t_list *a)
{
	if (a == NULL)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}
