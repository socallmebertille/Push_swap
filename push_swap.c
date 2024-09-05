/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:52:59 by saberton          #+#    #+#             */
/*   Updated: 2024/09/05 18:55:24 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list_node *a;
	t_list_node *b;

	a = NULL;
	b = NULL;
	if (ac == 1 || !av[1][0])
		return (EXIT_FAILURE);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	checks_init(av + 1, ac == 2, &a);
	if (!in_order(a))
	{
		if (count_node(a) == 2)
			sa(&a);
		else if (count_node(a) == 3)
			three_node_sort(&a);
		else
			push_algo(&a, &b);
	}
	free_list(&a);
	return (0);
}