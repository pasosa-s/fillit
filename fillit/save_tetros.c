/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_tetros.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:07:10 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/05/28 16:32:22 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_coord		*tetro_coord(char *str, int i, int j)
{
	t_coord		*coord;

	if (!str || !(coord = (t_coord *)malloc(sizeof(t_coord) * 4)))
		return (NULL);
	while (i < (int)ft_strlen(str))
	{
		if (str[i] != '.' && str[i] != '\n')
		{
			if (j == 0)
			{
				coord[j].x = i / 5;
				coord[j].y = i % 5;
			}
			else
			{
				coord[j].x = i / 5 - coord[0].x;
				coord[j].y = i % 5 - coord[0].y;
			}
			j++;
		}
		i++;
	}
	free(str);
	return (coord);
}

t_tetro				*save_tetros(char *str, int shapes)
{
	t_tetro		*tetros;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!(tetros = (t_tetro *)malloc(sizeof(t_tetro) * shapes + 1)))
		return (NULL);
	while (i < shapes)
	{
		tetros[i].letter = 'A' + i;
		if (!(tetros[i].coord = tetro_coord(ft_strsub(str, j, 20), 0, 0)))
			return (NULL);
		tetros[i].coord[0].x = 0;
		tetros[i].coord[0].y = 0;
		j += 21;
		i++;
	}
	return (tetros);
}
