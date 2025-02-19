/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_p1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:11:58 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/19 15:29:13 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	find_cost(t_node *a, t_node *b)
{
	t_node	*stack_a;

	if (a == NULL || b == NULL)
		return ;
	stack_a = a;
	while (stack_a)
	{
		stack_a->cost = stack_a->position;
		if (stack_a->median == false)
			stack_a->cost = node_len(a) - stack_a->position;
		if (stack_a->target->median == true)
			stack_a->cost += stack_a->target->position;
		else
			stack_a->cost += node_len(b) - stack_a->target->position;
		stack_a = stack_a->next;
	}
}

static t_node	*find_cheapest(t_node *a)
{
	long	cheapest;
	t_node	*cheapest_node;
	t_node	*current;

	if (a == NULL)
		return (NULL);
	cheapest = LONG_MAX;
	current = a;
	while (current)
	{
		if (current->cost < cheapest)
		{
			cheapest = current->cost;
			cheapest_node = current;
		}
		if (cheapest == 0)
			break ;
		current = current->next;
	}
	cheapest_node->cheapest = true;
	return (cheapest_node);
}

static void	find_target(t_node *a, t_node *b)
{
	long	closest;
	t_node	*target;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = a;
	while (stack_a)
	{
		closest = LONG_MIN;
		stack_b = b;
		while (stack_b)
		{
			if (stack_a->number > stack_b->number && stack_b->number > closest)
			{
				closest = stack_b->number;
				target = stack_b;
			}
			stack_b = stack_b->next;
		}
		if (closest == LONG_MIN)
			stack_a->target = find_max(b);
		else
			stack_a->target = target;
		stack_a = stack_a->next;
	}
}

void	push_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest;

	cheapest = find_cheapest(*a);
	if (cheapest->cost == 0)
	{
		pb(b, a);
		return ;
	}
	if (cheapest->median && cheapest->target->median)
		force_rr_to_top(a, b, cheapest);
	else if (!cheapest->median && !cheapest->target->median)
		force_rrr_to_top(a, b, cheapest);
	check2push(a, cheapest, 0);
	check2push(b, cheapest->target, 1);
	pb(b, a);
}

void	start_ps(t_node *a, t_node *b)
{
	position(a);
	position(b);
	find_target(a, b);
	find_cost(a, b);
	find_cheapest(a);
}
