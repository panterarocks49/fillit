/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 21:07:43 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/01 18:31:04 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			is_square_then_print(t_mino *minos)
{
	int		i;
	char	*str;

	i = 0;
	while (i < 19)
	{
		str = ft_strdup(minos[i].letters);
		if ((ft_strequ(minos[i].shape, "##..##") && str && *str == 'A'))
		{
			ft_putendl("AA\nAA");
			return (1);
		}
		ft_strdel(&str);
		i++;
	}
	return (0);
}

int			size_of_minos(t_mino *minos)
{
	int		size;
	int		i;
	int		j;

	size = 0;
	i = 0;
	while (i < 19)
	{
		j = 0;
		if (minos[i].letters)
		{
			while (minos[i].letters[j++])
				size++;
		}
		i++;
	}
	i = 0;
	size = size * 4;
	while (i * i < size)
		i++;
	return (i);
}

char		*make_board(char *board, int size)
{
	int		i;

	if (board)
		free(board);
	size *= size;
	board = ft_strnew(size);
	i = 0;
	while (i < size)
		board[i++] = '.';
	return (board);
}

void		print_board(char *board, int board_size)
{
	int	i;
	int j;

	i = 0;
	while (i < board_size)
	{
		j = 0;
		while (j < board_size)
		{
			ft_putchar(board[(i * board_size) + j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int			main(int argc, char **argv)
{
	char	*board;
	int		board_size;
	t_mino	*minos;

	if (argc != 2)
		usage_msg();
	minos = mino_init(argv[1]);
	board_size = size_of_minos(minos);
	if (board_size == 2 && board_size++ && is_square_then_print(minos))
		return (0);
	board = make_board(NULL, board_size);
	if (board_size == 3 && (!(filler(shrink(minos), board))))
	{
		board = make_board(board, ++board_size);
		minos = regrow(minos);
	}
	minos = grow(minos, board_size - 4);
	while (!filler(minos, board))
	{
		board = make_board(board, ++board_size);
		minos = grow(minos, 1);
	}
	print_board(board, board_size);
	return (0);
}
