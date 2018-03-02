/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:53:36 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/01 17:50:16 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*slice_board(char *board, int size)
{
	char	*str;
	char	*ptr;
	int		i;

	if (!(str = ft_strnew(size)) || (*board != '.' && *board != '#'))
		return (NULL);
	i = 1;
	ptr = str;
	while (*board && ptr - str < size && !(*board == '\n'
				&& *(board - 1) == '\n'))
	{
		if (!(i % 5) && *board != '\n')
			return (NULL);
		i++;
		if (*board == '\n')
			board++;
		else
			*ptr++ = *board++;
	}
	if (ft_strlen(str) == 16)
		if ((str = trim(str)))
			return (str);
	return (NULL);
}

static char	**read_fd(int fd)
{
	int		j;
	int		size;
	int		last_size;
	char	buf[BUF_SIZE];
	char	**arr;

	ft_bzero(buf, BUF_SIZE);
	j = 0;
	size = 0;
	last_size = 0;
	if (!(arr = (char **)ft_memalloc(sizeof(char *) * 27)))
		return (NULL);
	while ((size = read(fd, buf, BUF_SIZE)))
	{
		if (!(arr[j++] = slice_board(buf, size)))
			return (NULL);
		last_size = size;
	}
	if ((!size && !last_size) || (!size && last_size != 20))
		return (NULL);
	return (arr);
}

char		**read_input_file(char *file)
{
	int		fd;
	char	**arr;

	if (!(fd = open(file, O_RDONLY)))
		return (NULL);
	if (!(arr = read_fd(fd)))
		return (NULL);
	if (close(fd) == -1)
		return (NULL);
	return (arr);
}
