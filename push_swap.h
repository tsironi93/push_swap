/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:23:15 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/15 16:00:59 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>			//!!!!!!!!


typedef struct s_node
{
	int				number;
	struct s_node	*next;

}					t_node;

char	**ft_split(char *str, char seperator);

#endif