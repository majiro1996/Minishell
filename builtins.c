/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:41:45 by manujime          #+#    #+#             */
/*   Updated: 2023/05/17 18:05:40 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//changes the current directory to the one specified in the input
void	ft_cd(char **input)
{
	if (input[1] == NULL)
	{
		if (chdir(getenv("HOME")) != 0)
			perror("cd");
	}
	else if (chdir(input[1]) != 0)
	{
		printf("cd: %s", strerror(2));
		printf(": %s\n", input[1]);
	}
}

//prints the current working directory
void	ft_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		printf("pwd: %s\n", strerror(2));
	else
	{
		ft_putstr_fd(cwd, 1);
		ft_putstr_fd("\n", 1);
		free(cwd);
	}
}
