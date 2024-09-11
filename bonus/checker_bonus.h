/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 01:51:13 by saberton          #+#    #+#             */
/*   Updated: 2024/09/11 19:03:12 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	int				nb;
	char			*move;
	struct s_list	*previous;
	struct s_list	*next;
}					t_list;

void				checks_and_list(char **av, bool two_ac, t_list **a);
void				free_av(char **av);
void				free_list(t_list **a);
void				free_ope(t_list **ope);
void				free_all(t_list **a, t_list **b, t_list **ope);
int					sa(t_list **a);
int					sb(t_list **b);
int					ss(t_list **a, t_list **b);
int					ra(t_list **a);
int					rb(t_list **b);
int					rr(t_list **a, t_list **b);
int					rra(t_list **a);
int					rrb(t_list **b);
int					rrr(t_list **a, t_list **b);
int					pa(t_list **a, t_list **b);
int					pb(t_list **a, t_list **b);
int					ft_strlen(char *str);
int					free_init(t_list **a, char **av, bool two_ac);
int					ft_strcmp(char *s1, char *s2);
char				*get_next_line(int fd);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char c);
t_list				*ft_lstlast(t_list *a);
bool				in_order(t_list **a);

#endif