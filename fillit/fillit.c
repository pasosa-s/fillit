/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 21:28:18 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/05/27 13:18:44 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fillit(t_tetro *tetros, t_board b, int n_s, int shapes)
{
	int		i;
	int		j;

	i = 0;
	if (n_s == shapes)
		return (1);
	while (i < b.size)
	{
		j = 0;
		while (j < b.size)
		{
			if (is_placeable(tetros[n_s], b.board, i, j))
			{
				b.board = place_tetro(tetros[n_s], b.board, i, j);
				n_s++;
				if (fillit(tetros, b, n_s, shapes))
					return (1);
				else
					b.board = displace_tetro(tetros[--n_s], b.board, i, j);
			}
			j++;
		}
		i++;
	}
	return (0);
}
