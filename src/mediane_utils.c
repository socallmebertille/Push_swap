/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 01:32:22 by saberton          #+#    #+#             */
/*   Updated: 2024/09/11 19:01:05 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_tab(int len_a, int **tab)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < len_a - 1)
	{
		j = i + 1;
		while (j < len_a)
		{
			if ((*tab)[i] > (*tab)[j])
			{
				temp = (*tab)[i];
				(*tab)[i] = (*tab)[j];
				(*tab)[j] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	get_tab(int len_a, int **tab, t_list *a)
{
	int		i;
	t_list	*current;

	i = 0;
	current = a;
	*tab = malloc(len_a * sizeof(int));
	if (*tab == NULL)
		return ;
	while (i < len_a)
	{
		(*tab)[i] = current->nb;
		current = current->next;
		i++;
	}
}

static int	get_mediane(t_list *a, int len_a)
{
	int	*tab;
	int	i;
	int	j;
	int	med;

	i = 0;
	j = 0;
	tab = NULL;
	get_tab(len_a, &tab, a);
	if (tab == NULL)
		exit(EXIT_FAILURE);
	sort_tab(len_a, &tab);
	med = tab[len_a / 2];
	free(tab);
	return (med);
}

void	mediane_a_to_b(t_list **a, t_list **b)
{
	int	mid;
	int	med;

	med = get_mediane(*a, count_node(*a));
	mid = count_node(*a) / 2;
	while (mid > 0)
	{
		if ((*a)->nb <= med)
		{
			mid--;
			med = get_mediane(*a, count_node(*a));
			pb(a, b);
		}
		else
			ra(a);
	}
	return ;
}
