/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:23:15 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/19 15:43:13 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>			//!!!!!!!!
# include "./Libft/libft.h"
# include <limits.h>

typedef struct s_node
{
	int				number;
	struct s_node	*next;
	struct s_node	*target;
	int				cost;
	bool			median;
	int				position;
	bool			cheapest;
}					t_node;

int		spelling(char *str);
int		check_doubles(t_node *a, int num);
void	freeav(char **av);
void	free_nodes(t_node **a);
void	append(t_node **stack, int num);
void	error(t_node **a, char **av);
int		ft_abs(int a);


void	pa(t_node **a, t_node **b);
void	pb(t_node **b, t_node **a);
void	sa(t_node **a);
void	sb(t_node **a);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

bool	is_sorted(t_node *a);
int		node_len(t_node *a);
t_node	*find_max(t_node *a);
t_node	*find_min(t_node *a);
void	sort_3(t_node **a);

void	ptob(t_node **a, t_node **b);
void	start_ps(t_node *a, t_node *b);
void	finish_ps(t_node **a, t_node **b);
void	final(t_node **a);
void	position(t_node *a);
void	push_to_b(t_node **a, t_node **b);
void	force_rr_to_top(t_node **a, t_node **b, t_node *cheapest);
void	force_rrr_to_top(t_node **a, t_node **b, t_node *cheapest);
void	check2push(t_node **a, t_node *top, int flag);

#endif