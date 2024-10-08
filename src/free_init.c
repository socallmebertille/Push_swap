/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:16:07 by saberton          #+#    #+#             */
/*   Updated: 2024/09/08 05:09:25 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_av(char **av)
{
	int	i;

	i = -1;
	while (av[i])
		free(av[i++]);
	free(av - 1);
	return ;
}

void	free_list(t_list **a)
{
	t_list	*current;
	t_list	*temp;

	if (a == NULL)
		return ;
	current = *a;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*a = NULL;
	return ;
}

int	free_init(t_list **a, char **av, bool two_ac)
{
	free_list(a);
	if (two_ac)
		free_av(av);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
