/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 23:05:05 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/01 14:10:37 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_mino		*regrow(t_mino *minos)
{
	int i;
	int j;

	i = 0;
	while (i < 19)
	{
		j = 0;
		while (minos[i].shape[j])
		{
			if (minos[i].shape[j] == 'n')
				minos[i].shape[j] = '.';
			j++;
		}
		i++;
	}
	return (minos);
}

t_mino		*shrink(t_mino *minos)
{
	int i;
	int j;

	i = 0;
	while (i < 19)
	{
		j = 0;
		while (minos[i].shape[j])
		{
			if (minos[i].shape[j] == '.' && minos[i].shape[j - 1] == '#')
				minos[i].shape[j] = 'n';
			j++;
		}
		i++;
	}
	return (minos);
}

t_mino		*grow(t_mino *minos, int gb)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	*new_str;

	i = 0;
	while (i < 19 && gb)
	{
		new_str = grow_support(minos[i].shape, gb);
		j = 0;
		k = 0;
		while (minos[i].shape[j])
		{
			if (minos[i].shape[j - 1] == '#' && minos[i].shape[j] == '.')
			{
				l = gb;
				while (l--)
					new_str[k++] = '.';
			}
			new_str[k++] = minos[i].shape[j++];
		}
		minos[i++].shape = new_str;
	}
	return (minos);
}

char		*grow_support(char *str, int gb)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (str[j])
	{
		if (str[j - 1] == '#' && str[j] == '.')
			k += gb;
		j++;
	}
	return (ft_strnew(ft_strlen(str) + k));
}
