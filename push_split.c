/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:16:54 by saberton          #+#    #+#             */
/*   Updated: 2024/09/04 16:37:15 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count(const char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
		if (str[i] == '\0')
			return (count);
		else
			i++;
	}
	return (count);
}

static void	free_tab(char **tab, int count)
{
	while (count >= 0 && tab[count])
	{
		free(tab[count]);
		count--;
	}
	free(tab);
}

static char	**ft_tab(char const *s, char c, char **tab, int i)
{
	int	j;
	int	k;

	k = 1;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = 0;
			while (s[i + j] && s[i + j] != c)
				j++;
			tab[k] = ft_substr(s, i, j);
			if (tab[k] == NULL)
			{
				free_tab(tab, k - 1);
				return (NULL);
			}
			k++;
			i += j;
		}
	}
	tab[k] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	char	**tab;

	if (!s)
		return (NULL);
	while (*s == ' ')
		s++;
	len = ft_count(s, c);
	tab = (char **)malloc(sizeof(char *) * (len + 2));
	if (!tab)
		return (NULL);
	tab[0] = malloc(sizeof(char));
	if (!tab[0])
		return (NULL);
	tab[0][0] = '\0';
	tab = ft_tab(s, c, tab, 0);
	if (!tab)
		return (NULL);
	return (tab);
}
