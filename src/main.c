/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:04:30 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/15 18:03:35 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	_stack_init(t_node **a, char **av)
{
	int	i;
	int	num;

	i = 0;
	while (av[i])
	{
		num = ft_atoi(av[i]);
		append(a, num);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		_stack_init(&a, av);
		while (*av++)
			free(*av);
		free(av);
	}
	else
		_stack_init(&a, av + 1);
	while (a)
	{
		printf("%d\n", a->number);
		a = a->next;
	}
	return (0);
}
