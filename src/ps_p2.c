/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_p2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:18:09 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/19 23:06:43 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	position(t_node *a)
{
	int		i;
	int		median;
	t_node	*current;

	if (a == NULL)
		return ;
	i = 0;
	current = a;
	median = node_len(a) / 2;
	while (current)
	{
		current->position = i;
		if (i <= median)
			current->median = true;
		else
			current->median = false;
		i++;
		current = current->next;
	}
}

static void	find_target_home(t_node *a, t_node *b)
{
	long	closest;
	t_node	*target;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_b = b;
	while (stack_b)
	{
		closest = LONG_MAX;
		stack_a = a;
		while (stack_a)
		{
			if (stack_a->number > stack_b->number && stack_a->number < closest)
			{
				closest = stack_a->number;
				target = stack_a;
			}
			stack_a = stack_a->next;
		}
		if (closest == LONG_MAX)
			stack_b->target = find_min(a);
		else
			stack_b->target = target;
		stack_b = stack_b->next;
	}
}

void	finish_ps(t_node **a, t_node **b)
{
	position(*a);
	position(*b);
	find_target_home(*a, *b);
	check2push(a, (*b)->target, 0);
	pa(a, b);
}

void	final(t_node **a)
{
	while ((*a)->number != find_min(*a)->number)
	{
		if (find_min(*a)->median)
			ra(a);
		else
			rra(a);
	}
}
