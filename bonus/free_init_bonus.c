/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 03:48:30 by saberton          #+#    #+#             */
/*   Updated: 2024/09/11 06:54:14 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	free_ope(t_list **ope)
{
	t_list	*current;
	t_list	*temp;

	if (ope == NULL)
		return ;
	current = *ope;
	while (current)
	{
		temp = current->next;
		free(current->move);
		free(current);
		current = temp;
	}
	*ope = NULL;
	return ;
}

void	free_all(t_list **a, t_list **b, t_list **ope)
{
	free_list(a);
	free_list(b);
	free_ope(ope);
	exit(EXIT_FAILURE);
}

int	free_init(t_list **a, char **av, bool two_ac)
{
	free_list(a);
	if (two_ac)
		free_av(av);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
