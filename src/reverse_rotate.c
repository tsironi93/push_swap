/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:40:18 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/16 15:12:34 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_node **a)
{
	t_node	*temp;
	t_node	*first;

	if (a == NULL || (*a) == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	temp = (*a)->next;
	first = temp->next;
	while (first->next)
	{
		first = first->next;
		temp = temp->next;
	}
	temp->next = NULL;
	first->next = (*a);
	(*a) = first;
}

void	rra(t_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
