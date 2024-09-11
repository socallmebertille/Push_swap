/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:19:04 by saberton          #+#    #+#             */
/*   Updated: 2024/09/11 18:05:11 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_list	*ft_lstlast(t_list *a)
{
	if (a == NULL)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

bool	in_order(t_list **a)
{
	t_list	*stack_a;

	stack_a = *a;
	if (stack_a == NULL)
		return (true);
	while (stack_a->next)
	{
		if (stack_a->nb > stack_a->next->nb)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

int 	ft_strcmp(char *s1, char *s2)
{
    	while (*s1 && *s2 && *s1 == *s2)
    	{
            	s1++;
            	s2++;
    	}
    	return (*s1 - *s2);
}
void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
	write(fd, "\n", 1);
}
