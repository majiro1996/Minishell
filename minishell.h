/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:53:52 by manujime          #+#    #+#             */
/*   Updated: 2023/05/18 16:27:45 by manujime         ###   ########.fr       */
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
//init
void	ft_init_data(t_data *data, int argc, char **argv, char **envp);
void	ft_exit(char **input);

#endif