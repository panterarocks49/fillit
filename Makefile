# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrown <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 20:30:56 by jbrown            #+#    #+#              #
#    Updated: 2018/03/01 18:38:30 by jbrown           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
RM = /bin/rm -f

FUNCTS = fillit filler read tminosetup grow error trim place_mino
FLAGS = -Wall -Wextra -Werror

CFILES = $(patsubst %, %.c, $(FUNCTS))
OBJECTS = $(patsubst %, %.o, $(FUNCTS))

LIBDIR = ./libft
LIB = libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(LIBDIR)/$(LIB):
	@cd libft && make

$(OBJECTS):
	@gcc $(FLAGS) -c $(CFILES)

$(NAME): $(OBJECTS) $(LIBDIR)/$(LIB)
	@gcc $(FLAGS) $(OBJECTS) $(LIBDIR)/$(LIB) -o $(NAME)

clean:
	@$(RM) $(OBJECTS)
	@cd libft && make clean

fclean: clean
	@$(RM) $(NAME)
	@cd libft && make fclean

re: fclean all
