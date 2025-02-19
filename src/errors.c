/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turmoil <turmoil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 00:15:11 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/19 21:45:08 by turmoil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_doubles(t_node *a, int num)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->number == num)
			return (1);
		a = a->next;
	}
	return (0);
}

int	spelling(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}

void	error(t_node **a, char **av, bool avflag)
{
	write(1, "Error\n", 6);
	if (avflag)
		freeav(av);
	free_nodes(a);
	exit(1);
}
