/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tminosetup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:34:00 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/01 15:47:06 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_mino		*define_shapes(t_mino *minos)
{
	minos[0].shape = ft_strdup("####");
	minos[1].shape = ft_strdup("#...#...#...#");
	minos[2].shape = ft_strdup("#...###");
	minos[3].shape = ft_strdup("##..#...#");
	minos[4].shape = ft_strdup("###...#");
	minos[5].shape = ft_strdup("#...#..##");
	minos[6].shape = ft_strdup("#.###");
	minos[7].shape = ft_strdup("#...#...##");
	minos[8].shape = ft_strdup("###.#");
	minos[9].shape = ft_strdup("##...#...#");
	minos[10].shape = ft_strdup("##..##");
	minos[11].shape = ft_strdup("##.##");
	minos[12].shape = ft_strdup("#...##...#");
	minos[13].shape = ft_strdup("#..###");
	minos[14].shape = ft_strdup("#...##..#");
	minos[15].shape = ft_strdup("###..#");
	minos[16].shape = ft_strdup("#..##...#");
	minos[17].shape = ft_strdup("##...##");
	minos[18].shape = ft_strdup("#..##..#");
	return (minos);
}

static t_mino		*define_letters(t_mino *minos)
{
	int i;

	i = 0;
	while (i < 19)
	{
		minos[i].placed = 0;
		minos[i].letters = ft_strnew(26);
		i++;
	}
	return (minos);
}

static t_mino		*set_letters(char **arr, t_mino *minos)
{
	char	letter;
	int		i;
	int		j;

	letter = 'A';
	while (*arr)
	{
		i = -1;
		j = 0;
		while (++i < 19)
		{
			if (ft_strequ(*arr, minos[i].shape))
			{
				while (minos[i].letters[j])
					j++;
				minos[i].letters[j] = letter++;
				j = 1;
				break ;
			}
		}
		if (!j)
			error_msg();
		arr++;
	}
	return (minos);
}

int					count_minos(t_mino *minos)
{
	int i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		j = minos[i].placed;
		if (minos[i].letters)
		{
			while (minos[i].letters[j++])
				count++;
		}
		i++;
	}
	return (count);
}

t_mino				*mino_init(char *input)
{
	t_mino	*minos;
	char	**arr;

	if (!(arr = read_input_file(input)))
		error_msg();
	if (!(minos = malloc(sizeof(t_mino) * 19)))
		return (NULL);
	minos = define_shapes(minos);
	minos = define_letters(minos);
	minos = set_letters(arr, minos);
	return (minos);
}
