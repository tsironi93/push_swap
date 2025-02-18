/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:54:05 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/18 02:19:46 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	position (t_node *a)
{
	int		i;
	int		median;
	t_node	*current;

	if (a == NULL)
		return ;
	i = 0;
	current = a;
	median = node_len(a) / 2;
	printf("%d", median);
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
	int		closest;
	t_node	*target;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = a;
	while (stack_a)
	{
		closest = INT_MIN;
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
		if (closest == INT_MIN)
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
	print_stacks(a,b);
	print_tc(a);
}

void	ptob(t_node **a, t_node **b)
{
	//t_node	*temp;
	int	len_a;

	len_a = node_len(*a);
	//while (len_a-- > 3)
		pb(b, a);
		pb(b, a);
	// sort_3(a);
	start_ps(*a, *b);
}
