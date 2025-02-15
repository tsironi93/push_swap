/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:26:12 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/15 17:21:45 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	append(t_node **stack, int num)
{
	t_node	*node;
	t_node	*current;

	if (!stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->number = num;
	if (!*stack)
	{
		*stack = node;
	}
	else
	{
		current = *stack;
		while (current->next)
			current = current->next;
		current->next = node;
	}
	node->next = NULL;
}
