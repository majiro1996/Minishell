/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:53:52 by manujime          #+#    #+#             */
/*   Updated: 2023/05/17 15:21:36 by manujime         ###   ########.fr       */
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
}				t_data;

void	ft_cd(char **input);
void	ft_pwd(void);

#endif