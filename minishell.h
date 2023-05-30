/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgonza <albgonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:53:52 by manujime          #+#    #+#             */
/*   Updated: 2023/05/30 17:50:56 by albgonza         ###   ########.fr       */
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
# include <signal.h>

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
	int		actual_status;
}	t_data;

//builtins.c
void	ft_cd(t_data *data);
void	ft_pwd(void);
void	ft_echo(char **input);
//clean_up.c
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
char	**ft_parse(t_data *data);
//built_ins_2.c
void	ft_unset(t_data *data);
//signals.c
void	signal_setter(void);
#endif