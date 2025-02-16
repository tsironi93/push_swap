/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:23:15 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/16 02:19:14 by itsiros          ###   ########.fr       */
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

}					t_node;

void	append(t_node **stack, int num);
void	freeav(char **av);
void	free_nodes(t_node **a);
int		spelling(char *str);
void	error(t_node **a, char **av, char *str);
int		check_doubles(t_node *a, int num);


void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	sa(t_node **a);
void	sb(t_node **a);

#endif