/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:23:24 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/05/28 16:32:04 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		board_size(int shapes)
{
	int		i;

	i = 2;
	while (shapes * 4 > i * i)
		i++;
	return (i);
}

static char		*put_letters(char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = 'A';
	while (str[i])
	{
		if (str[i] == '#')
		{
			str[i] = c;
			j++;
		}
		if (j == 4)
		{
			j = 0;
			c++;
		}
		i++;
	}
	return (str);
}

static int		open_file(char *av, char **str, int *shapes)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];

	fd = open(av, O_RDONLY);
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = 0;
	close(fd);
	if (ret > 545 || !(is_valid_file(buf, shapes)))
		return (0);
	if (!(*str = ft_strdup(buf)))
		return (0);
	return (1);
}

static int		run_program(char *av)
{
	t_board		board;
	t_tetro		*tetros;
	char		*str;
	int			shapes;

	shapes = 1;
	if (open_file(av, &str, &shapes))
	{
		board.size = board_size(shapes);
		if (!(board.board = create_board(board.size)))
			return (0);
		if (!(tetros = save_tetros(put_letters(str), shapes)))
			return (0);
		while (!fillit(tetros, board, 0, shapes))
		{
			free_board(board);
			board.size++;
			if (!(board.board = create_board(board.size)))
				return (0);
		}
		ft_print_array(board.board, board.size);
		free_mem(tetros, board, str, shapes);
		return (1);
	}
	return (0);
}

int				main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!(run_program(av[1])))
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: fillit input_file\n");
	return (0);
}
