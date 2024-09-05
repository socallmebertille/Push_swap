/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:34:47 by saberton          #+#    #+#             */
/*   Updated: 2024/09/05 18:15:36 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_nb(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '+' || s[0] == '-')
		i++;
	if (!s[i])
		return (1);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i])
		return (1);
	return (0);
}

static int	is_double(long nb, t_list_node *a)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->nb == nb)
			return (1);
		a = a->next;
	}
	return (0);
}

static long	ft_atol(const char *str)
{
	long	nb;
	int		sign;
	int		i;

	nb = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

t_list_node	*find_last(t_list_node *a)
{
	if (a == NULL)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

static void	add_node(int nb, t_list_node **a)
{
	t_list_node	*new_node;
	t_list_node	*last;

	if (a == NULL)
		return ;
	new_node = malloc(sizeof(t_list_node));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->nb = nb;
	if (*a == NULL)
	{
		*a = new_node;
		new_node->previous = NULL;
	}
	else
	{
		last = find_last(*a);
		last->next = new_node;
		new_node->previous = last;
	}
}

void	checks_init(char **av, bool two_ac, t_list_node **a)
{
	int i;
	long nb;

	i = 0;
	while (av[i])
	{
		if (is_nb(av[i]) == 1)
			free_init(a, av, two_ac);
		nb = ft_atol(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			free_init(a, av, two_ac);
		if (is_double(nb, *a) == 1)
			free_init(a, av, two_ac);
		add_node((int)nb, a);
		i++;
	}
	if (two_ac)
		free_av(av);
	return ;
}