/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_node_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:49:02 by saberton          #+#    #+#             */
/*   Updated: 2024/09/06 21:23:21 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_node_sort(t_list_node **a)
{
	t_list_node	*biggest;

	biggest = find_biggest_node(*a);
	if (biggest == *a)
		ra(a);
	else if (biggest == (*a)->next)
		rra(a);
	if ((*a)->nb > (*a)->next->nb)
		sa(a);
}
// void	three_node_sort_b(t_list_node **b)
// {
// 	t_list_node	*biggest;

// 	biggest = find_biggest_node(*b);
// 	if (biggest == *b)
// 		rb(b);
// 	else if (biggest == (*b)->next)
// 		rrb(b);
// 	if ((*b)->nb > (*b)->next->nb)
// 		sb(b);
// }