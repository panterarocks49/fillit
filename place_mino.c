/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_mino.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 02:43:28 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/01 15:16:04 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	board_size(char *board)
{
	int	size;
	int	area;

	area = ft_strlen(board);
	size = 1;
	while (size * size < area)
		size++;
	return (size);
}

static char	*find_shape_place(char *shape, char *ret, int i)
{
	char	*shape_ptr;
	int		size;
	int		j;

	size = board_size(ret);
	while (ret[i])
	{
		shape_ptr = shape;
		j = i;
		while (((*shape_ptr == '#' && ret[j] == '.')
				|| (*shape_ptr == 'n' || *shape_ptr == '.')) && ret[j])
		{
			if (*shape_ptr == 'n')
				shape_ptr++;
			else if (!(j % size) && *shape_ptr == '#'
					&& *(shape_ptr - 1) == '#')
				break ;
			shape_ptr++;
			j++;
		}
		if (!*shape_ptr)
			return ((ret + i));
		i++;
	}
	return (NULL);
}

char		*place_mino(t_mino *mino, char letter, char *ret, int offset)
{
	char	*shape;
	char	*start;

	shape = mino->shape;
	if ((ret = find_shape_place(shape, ret, offset)))
	{
		start = ret;
		while (*shape && *ret)
		{
			if (*shape == 'n')
				shape++;
			if (*shape == '#')
				*ret = letter;
			shape++;
			ret++;
		}
		mino->placed++;
		return (start);
	}
	return (NULL);
}
