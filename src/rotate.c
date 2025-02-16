/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 02:32:01 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/16 02:41:17 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_node **a)
{
	t_node	*temp;
	t_node	*first;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	*a = (*a)->next;
	temp = *a;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	first->next == NULL;
}

void	ra(t_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_node **a,t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
