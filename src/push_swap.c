/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:54:05 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/19 03:36:50 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

static void find_cost(t_node *a, t_node *b)
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

static void	position(t_node *a)
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

static void	start_ps(t_node *a, t_node *b)
{
	position(a);
	position(b);
	find_target(a, b);
	find_cost(a, b);
	find_cheapest(a);
}

static void	force_rr_to_top(t_node **a, t_node **b, t_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rr(a, b);
	position(*a);
	position(*b);
}

static void	force_rrr_to_top(t_node **a, t_node **b, t_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rrr(a, b);
	position(*a);
	position(*b);
}

static void check2push(t_node **a, t_node *top, int flag)
{
	while (*a != top)
	{
		if (flag == 0)
		{
			if (top->median)
				ra(a);
			else
				rra(a);
		}
		else if (flag == 1)
		{
			if (top->median)
				rb(a);
			else
				rrb(a);
		}
	}
}

static void push_to_b(t_node **a, t_node **b)
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

static void find_target_home(t_node *a, t_node *b)
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

static void finish_ps(t_node **a, t_node **b)
{
	position(*a);
	position(*b);
	find_target_home(*a, *b);
}

static void	push_back(t_node **a, t_node **b)
{
	check2push(a, (*b)->target, 0);
	pa(a, b);
}

static void final(t_node **a)
{
	while ((*a)->number != find_min(*a)->number)
	{
		if (find_min(*a)->median)
			ra(a);
		else
			rra(a);
	}
}

void	ptob(t_node **a, t_node **b)
{
	int	len_a;

	len_a = node_len(*a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a);
	while (len_a-- > 3)
	{
		start_ps(*a, *b);
		push_to_b(a, b);
	}
	sort_3(a);
	while (*b)
	{
 		finish_ps(a, b);
		push_back(a, b);
	}
	position(*a);
	final(a);
}
