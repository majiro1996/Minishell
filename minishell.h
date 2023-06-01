/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:53:52 by manujime          #+#    #+#             */
/*   Updated: 2023/06/01 16:29:59 by manujime         ###   ########.fr       */
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

# define N0_QUOTE 0
# define SI_QUOTE 1
# define DO_QUOTE 2

typedef struct s_input
{
	char			*content;
	int				type;
	struct s_input	*next;
	struct s_input	*prev;
}	t_input;

typedef struct s_data
{
	char	*line;
	char	**input;
	t_input	*list;
	char	**envp;
	char	**argv;
	int		argc;
}	t_data;

//builtins.c
void	ft_cd(t_data *data);
void	ft_pwd(void);
void	ft_echo(char **input);
//clean_up.c
void	ft_clean_paths(char **paths);
void	ft_clean_input(t_data *data);
void	ft_leaks(void);
//init.c
void	ft_init_data(t_data *data, int argc, char **argv, char **envp);
void	ft_exit(char **input);
void	ft_export(t_data *data);
//export_utils.c
char	*ft_get_var(char *env);
void	ft_print_env(char **envp);
int		ft_add_env(t_data *data);
int		ft_update_env(t_data *data);
//parser.c
char	*ft_get_env(char *line, t_data *data);
void	ft_parse(t_data *data);
//parser_sign.c
void	ft_search_and_replace(t_data *data);
//parser_list.c
void	ft_input_parse(t_data *data);
//built_ins_2.c
void	ft_unset(t_data *data);
//updates_at_start.c
void	ft_shlvl(t_data *data);
void	ft_shell_name(t_data *data);
#endif