/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:41:45 by manujime          #+#    #+#             */
/*   Updated: 2023/05/17 15:13:37 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//changes the current directory to the one specified in the input
void	ft_cd(char **input)
{
	if (input[1] == NULL)
	{
		if (chdir(getenv("HOME")) != 0)
			perror("minishell3");
	}
	else if (chdir(input[1]) != 0)
		perror("bad path");
}

//prints the current working directory
void	ft_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		perror("minishell4");
	else
	{
		ft_putstr_fd(cwd, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		free(cwd);
	}
}
