# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmabe <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/17 14:36:45 by nmabe             #+#    #+#              #
#    Updated: 2018/08/21 09:57:22 by nmabe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	nmabe.filler

SRC = 	flr_filler.c		\
		flr_play.c			\
		flr_get_board.c		\
		flr_get_player.c	\
		flr_check_token.c	\
		get_next_line.c		\

HEADER = -L includes

CC = gcc -o $(NAME)

FLAGS = -Wall -Wextra -Werror

LFLAGS = -L./libft -lft

all:
	@make -C libft/ fclean && make -C libft/
	$(CC) $(FLAGS) $(SRC) $(HEADER) $(LFLAGS)
	@echo "\n \x1b[32m $(NAME) iyenziwe !!!...\n \x1b[0m"

clean:
	@rm -f $(NAME)
	@rm -f *.o
	@make clean -C libft/
	@echo "\n \x1b[31m $(NAME) isukile !!!...\n \x1b[0m"

fclean: clean
		@make -C libft/ fclean

re:
	fclean
	all
