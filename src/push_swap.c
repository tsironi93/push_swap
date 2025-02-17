/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:54:05 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/17 01:09:23 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	find_target(t_node **a, t_node **b)
{
	int		closest;
	int		calc;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = *a;
	while (stack_a)
	{
		closest = INT_MAX;
		stack_b = *b;
		while (stack_b)
		{
			calc = abs(stack_a->number - stack_b->number);
			if (stack_a->number < find_min(*b)->number)
				stack_a->target = find_max(*b)->number;
			else if(calc < closest)
			{
				closest = calc;
				stack_a->target = stack_b->number;
			}
			stack_b = stack_b->next;
		}
		stack_a = stack_a->next;
	}
}

void	ptob(t_node **a, t_node **b)
{
	//t_node	*temp;

	if (node_len(*a) > 5)
	{
		pb(b, a);
		pb(b, a);
	}
	else
		pb(b, a);
	//find_max(*b);
	//find_min(*b);
	find_target(a, b);

	// sort_3(a);
}
