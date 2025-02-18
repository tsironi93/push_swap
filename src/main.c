/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:04:30 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/18 04:34:36 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long	ft_latoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static void	_stack_init(t_node **a, char **av)
{
	int		i;
	long	num;

	i = 0;
	while (av[i])
	{
		if (spelling(av[i]))
			error(a, av, "SPELLING PROBLEM");
		num = ft_latoi(av[i]);
		if (num < INT_MIN || num > INT_MAX)
			error(a, av, "SURPASSED INT");
		if (check_doubles(*a, num))
			error(a, av, "DOUBLES FOUND");
		append(a, num);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	atexit(leaks);
	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		_stack_init(&a, av);
		freeav(av);
	}
	else
		_stack_init(&a, av + 1);
	if (!is_sorted(a))
	{
		if (node_len(a) == 3)
			sort_3(&a);
		ptob(&a, &b);
	}
	free_nodes(&b);
	free_nodes(&a);
	return (0);
}
