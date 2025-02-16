/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 00:15:11 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/16 16:40:33 by itsiros          ###   ########.fr       */
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
	if (*str != '+' && *str != '-' && *str <= '0' && *str >= '9')
		return (1);
	if (*str == '+' && *str == '-' && !(*str >= '0' && *str <= '9'))
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

void	error(t_node **a, char **av, char *str)
{
	// free_nodes(a);	
	// freeav(av);
	a = NULL;
	av = NULL;
	write(1, "ERROR: ", 7);
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write (1, "\n", 1);
	exit(1);
}
