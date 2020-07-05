/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_tetro.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:05:07 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/05/21 15:21:13 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**displace_tetro(t_tetro tetro, char **board, int row, int col)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		board[row + tetro.coord[i].x][col + tetro.coord[i].y] = '.';
		i++;
	}
	return (board);
}

char	**place_tetro(t_tetro tetro, char **board, int row, int col)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		board[row + tetro.coord[i].x][col + tetro.coord[i].y] = tetro.letter;
		i++;
	}
	return (board);
}
