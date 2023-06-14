# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 22:40:46 by manujime          #+#    #+#              #
#    Updated: 2023/06/14 12:55:15 by manujime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a

GREEN		=		\033[0;32m
RED			=		\033[0;31m
END			=		\033[0m

SRC =   main.c \
		exe_utils.c \
		builtins.c \
		init.c \
		clean_up.c \
		export_utils.c \
		parser.c \
		parser_sign.c \
		parser_list.c \
		built_ins_2.c \
		updates_at_start.c \
		pipes.c \
		redirects.c \
		signals.c \
		here_document.c \

OBJ = $(SRC:.c=.o)

INC		= -I/Users/$(USER)/.brew/opt/readline/include

LFLAGS	= -L/Users/$(USER)/.brew/opt/readline/lib -lreadline

NAME = minishell

all: $(NAME) tmp

$(LIBFT):
	@make extra -C libft
	
$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LFLAGS) $(INC) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled$(END)"


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

bonus: $(BONUS)

tmp:
	@mkdir tmp
	@touch tmp/.here_docminishell.tmp

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@echo "$(RED)$(NAME) deleted$(END)"
	@rm -rf tmp

re: fclean all

.PHONY: all clean fclean re

