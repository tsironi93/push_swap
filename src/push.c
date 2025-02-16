/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 01:33:05 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/16 02:22:48 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void push(t_node **dest, t_node ** src)
{
	t_node	*node;

	if (src == NULL)
		return ;
	node = *src;
	(*src) = (*src)->next;
	if (dest == NULL)
	{
		(*dest) = node;
		node->next = NULL;
	}
	else
	{
		node->next = *dest;
		*dest = node;
	}
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
