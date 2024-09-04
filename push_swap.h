/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:41:43 by saberton          #+#    #+#             */
/*   Updated: 2024/09/04 19:18:08 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list_node
{
	int					nb;
	int					position;
	int					cost;
	bool				mediane;
	bool				cheapest;
	struct s_list_node	*target;
	struct s_list_node	*previous;
	struct s_list_node	*next;
}	t_list_node ;

t_list_node *find_last(t_list_node *a);
void    free_av(char **av);
void    checks_init(char **av, bool two_ac, t_list_node **a);
int    free_init(t_list_node **a, char **av, bool two_ac);
void    free_list(t_list_node **a);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
bool in_order(t_list_node *a);
int count_node(t_list_node *a);
void    sa(t_list_node **a);
void    sb(t_list_node **b);
void    ss(t_list_node **a, t_list_node **b);
t_list_node *find_biggest_node(t_list_node *a);
void    three_node_sort(t_list_node **a);
void    ra(t_list_node **a);
void    rb(t_list_node **b);
void    rr(t_list_node **a, t_list_node **b);
void    rra(t_list_node **a);
void    rrb(t_list_node **b);
void    rrr(t_list_node **a, t_list_node **b);

#endif