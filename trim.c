/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 02:11:37 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/01 02:12:16 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t	get_beg(char const *s)
{
	size_t beg;

	beg = 0;
	while ((s[beg] == '.') && s[beg])
		beg++;
	return (beg);
}

static size_t	get_end(char const *s)
{
	size_t end;

	end = ft_strlen(s) - 1;
	while ((s[end] == '.') && end > 0)
		end--;
	return (end);
}

char			*trim(char const *s)
{
	size_t	beg;
	size_t	end;
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (*s == '\0')
		return ((char *)s);
	beg = get_beg(s);
	end = get_end(s);
	if (beg > end)
	{
		if (!(str = (ft_strnew(0))))
			return (NULL);
		return (str);
	}
	if (!(str = (ft_strnew(end - beg + 1))))
		return (NULL);
	i = -1;
	while (beg + ++i <= end)
		str[i] = s[beg + i];
	str[i] = '\0';
	return (str);
}
