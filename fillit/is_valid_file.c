/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:50:10 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/05/21 15:28:31 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		count_shapes(char *str, int *shapes)
{
	int		i;
	int		nn;

	i = 0;
	nn = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			nn++;
			if (nn % 5 == 0)
				(*shapes)++;
		}
		i++;
	}
	if (*shapes > 26)
		return (0);
	return (1);
}

static int		count_blocks(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '#')
			count++;
		i++;
	}
	return (count);
}

static int		is_valid_content(char *str)
{
	int		i;
	int		sep;

	i = 0;
	sep = 0;
	while (str[i])
	{
		if (str[i] == '.' || str[i] == '#')
		{
			if (20 * (sep + 1) + sep == i && str[i] != '\n')
				return (0);
			i++;
		}
		else if ((i + 1 - sep) % 5 == 0 && str[i] == '\n')
			i++;
		else if ((i - sep) % 20 == 0 && str[i] == '\n')
		{
			i++;
			sep++;
		}
		else
			return (0);
	}
	return (1);
}

int				is_valid_file(char *str, int *shapes)
{
	if (!(count_shapes(str, shapes)) ||
		((int)(ft_strlen(str)) != (*shapes * 20 + *shapes - 1)) ||
		(count_blocks(str) != *shapes * 4) ||
		(!(is_valid_content(str))) ||
		(!(count_adj_blocks(str, *shapes))))
		return (0);
	return (1);
}
