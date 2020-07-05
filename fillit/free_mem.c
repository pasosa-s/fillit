/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:04:31 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/05/27 17:01:40 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_board(t_board board)
{
	int		i;

	i = 0;
	while (i < board.size)
	{
		free(board.board[i]);
		i++;
	}
	free(board.board[i]);
	free(board.board);
}

void		free_mem(t_tetro *tetros, t_board board, char *str, int shapes)
{
	int		i;

	i = 0;
	while (i < shapes)
	{
		free(tetros[i].coord);
		i++;
	}
	free(str);
	free(tetros);
	free_board(board);
}
