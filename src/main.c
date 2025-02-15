/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:04:30 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/16 00:09:25 by itsiros          ###   ########.fr       */
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

static void	test(t_node *a)
{
	while (a)
	{
		printf("%d\n", a->number);
		a = a->next;
	}
}

static void	_leaks(void)
{
	system ("leaks push_swap");
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	atexit(_leaks);
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		_stack_init(&a, av);
		freeav(av);
	}
	else
		_stack_init(&a, av + 1);
	test(a);
	free_nodes(&a);
	return (0);
}
