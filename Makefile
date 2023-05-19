# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 22:40:46 by manujime          #+#    #+#              #
#    Updated: 2023/05/17 13:09:26 by manujime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

GREEN		=		\033[0;32m
RED			=		\033[0;31m
END			=		\033[0m

SRC =   main.c \
		builtins.c \
		redirections.c \

OBJ = $(SRC:.c=.o)

NAME = minishell

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -l readline
	@echo "$(GREEN)$(NAME) compiled"

$(LIBFT):
	@make extra -C libft

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@echo "$(RED)$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re

