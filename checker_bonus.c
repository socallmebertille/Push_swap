/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 01:44:24 by saberton          #+#    #+#             */
/*   Updated: 2024/09/11 12:31:38 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static char	*recup_ope(char *str, char c)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(str)));
	if (!dup)
		return (NULL);
	while (str[i] != c)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static void	add_ope(t_list **ope, char *str)
{
	t_list	*new_node;
	t_list	*last;

	if (ope == NULL)
		return ;
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->move = recup_ope(str, '\n');
	if (new_node->move == NULL)
	{
		free_ope(ope);
		exit(EXIT_FAILURE);
	}
	new_node->previous = NULL;
	if (*ope == NULL)
		*ope = new_node;
	else
	{
		last = ft_lstlast(*ope);
		last->next = new_node;
		new_node->previous = last;
	}
}

static int	check_ope(char *ope, t_list **a, t_list **b)
{
	if (ft_strncmp(ope, "sa", 2) == 0)
		return (sa(a));
	else if (ft_strncmp(ope, "sb", 2) == 0)
		return (sb(b));
	else if (ft_strncmp(ope, "ss", 2) == 0)
		return (ss(a, b));
	else if (ft_strncmp(ope, "rra", 3) == 0)
		return (rra(a));
	else if (ft_strncmp(ope, "rrb", 3) == 0)
		return (rrb(b));
	else if (ft_strncmp(ope, "rrr", 3) == 0)
		return (rrr(a, b));
	else if (ft_strncmp(ope, "ra", 2) == 0)
		return (ra(a));
	else if (ft_strncmp(ope, "rb", 2) == 0)
		return (rb(b));
	else if (ft_strncmp(ope, "rr", 2) == 0)
		return (rr(a, b));
	else if (ft_strncmp(ope, "pa", 2) == 0)
		return (pa(a, b));
	else if (ft_strncmp(ope, "pb", 2) == 0)
		return (pb(a, b));
	else
		return (1);
}

static void	made_ope(t_list **ope, t_list **a, t_list **b)
{
	int		check;
	char	*str;
	t_list	*temp;

	check = 0;
	str = get_next_line(STDIN_FILENO);
	while (str != NULL)
	{
		add_ope(ope, str);
		free(str);
		str = get_next_line(STDIN_FILENO);
	}
	if (!ope)
		return ;
	while (*ope)
	{
		check = check_ope((*ope)->move, a, b);
		if (check == 1)
			free_all(a, b, ope);
		temp = *ope;
		*ope = (*ope)->next;
		free(temp->move);
		free(temp);
	}
	return ;
}

int	main(int ac, char **av)
{
	t_list	*ope;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || !av[1][0])
		return (EXIT_FAILURE);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (av == NULL)
			exit(EXIT_FAILURE);
	}
	checks_and_list(av + 1, ac == 2, &a);
	ope = NULL;
	made_ope(&ope, &a, &b);
	if (in_order(&a) == true && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (b)
		free_list(&b);
	free_list(&a);
	return (0);
}
