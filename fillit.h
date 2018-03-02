/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 19:46:44 by jbrown            #+#    #+#             */
/*   Updated: 2018/03/01 17:32:17 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

# define BUF_SIZE 21

typedef struct	s_mino
{
	char	*shape;
	char	*letters;
	int		placed;
}				t_mino;

t_mino			*mino_init(char *input);

t_mino			*grow(t_mino *minos, int bs);
char			*grow_support(char *str, int gb);
t_mino			*shrink(t_mino *minos);
t_mino			*regrow(t_mino *minos);

void			print_minos(t_mino *minos);
void			print_board(char *board, int board_size);

int				is_square_then_print(t_mino *minos);
void			error_msg(void);
void			usage_msg(void);

char			*place_mino(t_mino *mino, char letter, char *ret, int offset);

int				count_minos(t_mino *minos);

char			*trim(char const *s);

char			**read_input_file(char *file);

int				filler(t_mino *minos, char *ret);

#endif
