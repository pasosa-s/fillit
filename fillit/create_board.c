/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_board.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:32:26 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/05/28 16:32:20 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**create_board(int size)
{
	char	**board;
	int		i;

	if (!(board = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(board[i] = ft_strnew_char(size, '.')))
			return (NULL);
		i++;
	}
	if (!(board[i] = ft_strnew(size)))
		return (NULL);
	return (board);
}
