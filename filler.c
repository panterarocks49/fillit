/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:17:02 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/01 17:00:58 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		scrub_mino(t_mino *mino, char letter, char *ret)
{
	mino->placed--;
	while (*ret)
	{
		if (*ret == letter)
			*ret = '.';
		ret++;
	}
}

static int		untried_mino(t_mino *mino, char letter)
{
	if (mino)
		if (mino->letters[mino->placed] == letter)
			return (1);
	return (0);
}

static int		unused_letter(char letter, char *ret)
{
	while (*ret)
		if (*ret++ == letter)
			return (0);
	return (1);
}

static t_mino	*find_mino(t_mino *minos, char *ret, char letter)
{
	int		i;
	int		j;

	i = 0;
	while (i < 19)
	{
		if (minos[i].letters)
		{
			j = 0;
			while (minos[i].letters[j] != letter && minos[i].letters[j])
				j++;
			if (minos[i].letters[j])
			{
				if (unused_letter(letter, ret)
					&& untried_mino((minos + i), letter))
					return (minos + i);
				return (NULL);
			}
		}
		i++;
	}
	return (NULL);
}

int				filler(t_mino *minos, char *ret)
{
	char	letter;
	char	*place;
	int		i;
	t_mino	*mino;

	letter = 'A' - 1;
	while (++letter <= 'Z')
		if ((mino = find_mino(minos, ret, letter)))
		{
			i = 0;
			place = (ret - 1);
			while ((place = place_mino(mino, letter, ret, (place - ret + 1)))
					&& i++ < 4)
			{
				if (filler(minos, ret))
					return (1);
				scrub_mino(mino, letter, ret);
			}
			if (!unused_letter(letter, ret))
				scrub_mino(mino, letter, ret);
			if (!i)
				return (0);
		}
	return (!count_minos(minos));
}
