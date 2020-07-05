/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_adj_blocks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:49:18 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/05/27 20:45:51 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		is_valid(char *str)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (str[i - 5] && str[i - 5] == '#')
				counter++;
			if (str[i - 1] && str[i - 1] == '#')
				counter++;
			if (str[i + 1] && str[i + 1] == '#')
				counter++;
			if (str[i + 5] && str[i + 5] == '#')
				counter++;
		}
		i++;
	}
	free(str);
	return (counter >= 6 ? 1 : 0);
}

int				count_adj_blocks(char *str, int shapes)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (counter < shapes)
	{
		if (!(is_valid(ft_strsub(str, i, 20))))
			return (0);
		counter++;
		i += 21;
	}
	return (1);
}
