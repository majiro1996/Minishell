/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:53:52 by manujime          #+#    #+#             */
/*   Updated: 2023/05/19 18:37:22 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <sys/wait.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;36m"
# define END "\033[0m"

typedef struct s_data
{
	char	*line;
	char	**input;
	char	**envp;
	char	**argv;
	int		argc;
}	t_data;

//builtins.c
void	ft_cd(char **input);
void	ft_pwd(void);
void	ft_echo(char **input);
//clean_up.c
void	ft_clean_input(t_data data);
void	ft_leaks(void);
//init.c
void	ft_init_data(t_data *data, int argc, char **argv, char **envp);
void	ft_exit(char **input);
void	ft_export(char **input, char **envp);
//utils.c
void	ft_print_env(char **envp);
void	ft_add_env(char *input, char **envp);

#endif