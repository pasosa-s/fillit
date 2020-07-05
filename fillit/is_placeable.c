/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_place.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:52:19 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/05/22 19:19:05 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			is_placeable(t_tetro tetro, char **board, int x, int y)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		if (board[x + tetro.coord[i].x][y + tetro.coord[i].y] == '.')
			i++;
		else
			return (0);
	}
	return (1);
}
