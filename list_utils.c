/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:09:28 by saberton          #+#    #+#             */
/*   Updated: 2024/09/07 00:07:08 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	in_order(t_list_node *a)
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

int	count_node(t_list_node *a)
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

t_list_node	*find_biggest_node(t_list_node *a)
{
	t_list_node	*biggest;
	int			i;

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

t_list_node	*find_lowest_node(t_list_node *a)
{
	t_list_node	*lowest;
	int			i;

	if (a == NULL)
		return (NULL);
	lowest = NULL;
	i = INT_MAX;
	while (a)
	{
		if (i > a->nb)
		{
			lowest = a;
			i = a->nb;
		}
		a = a->next;
	}
	return (lowest);
}

t_list_node	*find_last(t_list_node *a)
{
	if (a == NULL)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}
