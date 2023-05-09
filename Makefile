# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 22:40:46 by manujime          #+#    #+#              #
#    Updated: 2023/05/09 22:44:31 by manujime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

SRC =   main.c \

OBJ = $(SRC:.c=.o)

NAME = minishell

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -l readline

$(LIBFT):
	make extra -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re

