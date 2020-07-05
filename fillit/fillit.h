/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:25:37 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/05/28 16:32:29 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 546
# define ARRAY_SIZE 26

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

typedef struct	s_tetro
{
	char		letter;
	t_coord		*coord;
}				t_tetro;

typedef struct	s_board
{
	int			size;
	char		**board;
}				t_board;

int				is_valid_file(char *str, int *shapes);
int				count_adj_blocks(char *str, int shapes);
char			**create_board(int shapes);
int				fillit(t_tetro *tetros, t_board board, int n_s, int shapes);
int				is_placeable(t_tetro tetro, char **board, int x, int y);
t_tetro			*save_tetros(char *str, int shapes);
char			**place_tetro(t_tetro tetro, char **board, int row, int col);
char			**displace_tetro(t_tetro tetro, char **board, int row, int col);
void			free_board(t_board board);
void			free_mem(t_tetro *tetros, t_board board, char *str, int shapes);

#endif
