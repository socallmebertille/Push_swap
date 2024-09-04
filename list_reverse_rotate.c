/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:55:38 by saberton          #+#    #+#             */
/*   Updated: 2024/09/04 19:14:40 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void reverse_rotate(t_list_node **a)
{
    t_list_node *last;

    last = find_last(*a);
    last->previous->next = NULL;
    last->next = *a;
    last->previous = NULL;
    *a = last;
    last->next->previous = last;
}
void    rra(t_list_node **a)
{
    reverse_rotate(a);
    write (1, "rra\n", 4);
}

void    rrb(t_list_node **b)
{
    reverse_rotate(b);
    write (1, "rrb\n", 4);
}

void    rrr(t_list_node **a, t_list_node **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write (1, "rrr\n", 4);
}