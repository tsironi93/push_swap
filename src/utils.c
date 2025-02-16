/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:21:07 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/16 16:21:36 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	freeav(char **av)
{
	int	i;

	i = 0;
	if (av == NULL || *av == NULL)
		return ;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

bool	is_sorted(t_node *a)
{
	if (a == NULL)
		return (true);
	while (a->next)
	{
		if (a->number > a->next->number)
			return (false);
		a = a->next;
	}
	return (true);
}

t_node	*find_max(t_node *a)
{
	int		max;
	t_node	*max_node;

	if (a == NULL)
		return (NULL);
	max = INT_MIN;
	while (a)
	{
		if (a->number > max)
		{
			max = a->number;
			max_node = a;
		}
		a = a->next;
	}
	return (max_node);
}

void	sort_3(t_node **a)
{
	t_node	*max;

	max = find_max(*a);
	if (*a == max)
		ra(a);
	else if ((*a)->next == max)
		rra(a);
	if ((*a)->number > (*a)->next->number)
		sa(a);
}
