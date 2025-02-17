/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:04:30 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/17 00:13:26 by itsiros          ###   ########.fr       */
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

static void	test(t_node *a, t_node *b)
{
	if (is_sorted(a) && node_len(b) == 0)
		printf("\n\n\n\t---------------!!!SUCCESS!!!---------------\n");
	else
		printf("\n\n\n\t---------------!!!FAILURE!!!---------------\n");
	printf("\n---Stack A---\n");
	while (a)
	{
		printf("| %d\t|\n", a->number);
		a = a->next;
	}
	printf("\n---Stack B---\n");
	while (b)
	{
		printf("| %d\t|\n", b->number);
		b = b->next;
	}
	printf("\n\n\n");
}

static void	test2(t_node *a, t_node *b)
{
	b = NULL;
	printf("\n---Stack A: Targets---\n");
	while (a)
	{
		printf("| %d\t|\n", a->target);
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
	if (!is_sorted(a))
	{
		if (node_len(a) == 3)
			sort_3(&a);
		ptob(&a, &b);
	}
	test(a, b);
	test2(a, b);
	free_nodes(&b);
	free_nodes(&a);
	return (0);
}
