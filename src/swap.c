/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 01:42:42 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/16 02:26:28 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_node **a)
{
	t_node *temp;

	if (*a == NULL || a == NULL || (*a)->next == NULL)
		return ;
	temp = (*a)->next;
	(*a)->next = temp->next;
	temp->next = *a;
	*a = temp;
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
