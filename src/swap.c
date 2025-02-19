/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 01:42:42 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/19 23:06:53 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_node **a)
{
	t_node	*first;
	t_node	*second;

	if (*a == NULL || a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
}

void	sa(t_node **a)
{
	swap (a);
	write(1, "sa\n", 3);
}

void	sb(t_node **a)
{
	swap (a);
	write(1, "sb\n", 3);
}
