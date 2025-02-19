/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:54:05 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/19 15:31:21 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	force_rr_to_top(t_node **a, t_node **b, t_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rr(a, b);
	position(*a);
	position(*b);
}

void	force_rrr_to_top(t_node **a, t_node **b, t_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rrr(a, b);
	position(*a);
	position(*b);
}

void	check2push(t_node **a, t_node *top, int flag)
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
		finish_ps(a, b);
	position(*a);
	final(a);
}
