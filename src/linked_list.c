/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:26:12 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/16 16:16:12 by itsiros          ###   ########.fr       */
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
	node->next = NULL;
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
}

void	free_nodes(t_node **a)
{
	t_node	*temp;
	t_node	*current;

	if (a == NULL)
		return ;
	current = *a;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*a = NULL;
}

int	node_len(t_node *a)
{
	int	len;

	len = 0;
	if (a == NULL)
		return (0);
	while (a)
	{
		len++;
		a = a->next;
	}
	return (len);
}
