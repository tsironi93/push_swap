/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:51:54 by itsiros           #+#    #+#             */
/*   Updated: 2025/02/11 21:10:00 by itsiros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "././push_swap.h"

static int	count_words(char *str, char seperator)
{
	int	count;
	int	inside_flag;

	count = 0;
	while (str)
	{
		inside_flag = 0;
		while (*str == seperator)
			str++;
		while (*str && *str != seperator)
		{
			if (inside_flag)
			{
				count++;
				inside_flag = 1;
			}
			str++;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char seperator)
{
	static int	pointer;
	char		*new_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[pointer] == seperator)
		pointer++;
	while (str[pointer + len] != seperator && str[pointer + len])
		len++;
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	while (str[pointer] != seperator && str[pointer])
		new_str[i++] = str[pointer++];
	new_str[i] = '\0';
	return (new_str);
}

char	**ft_split(char *str, char seperator)
{
	int		count;
	char	**table;
	int		i;

	i = 0;
	count = count_words(str, seperator);
	table = malloc(sizeof(char *) * (count + 2));
	if (!table)
		return (NULL);
	while (count-- >= 0)
	{
		if (!i)
		{
			table[i] = malloc(sizeof (char));
			if (!table[i])
				return (NULL);
			table[i][0] = '\0';
			i++;
			continue ;
		}
		table[i] = get_next_word(str, seperator);
		i++;
	}
	table[i] == NULL;
	return (table);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long int	result;

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
