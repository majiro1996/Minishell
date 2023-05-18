/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:41:45 by manujime          #+#    #+#             */
/*   Updated: 2023/05/18 10:34:36 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//changes the current directory to the one specified in the input
//if no input is specified, it changes the current directory to the home
//directory
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

//gets the curent working directory and prints it to stdout
//if an error occurs, it prints the error to stderr
void	ft_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		perror("pwd");
	else
	{
		ft_putstr_fd(cwd, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		free(cwd);
	}
}

//prints the input to stdout, checks if there is a -n flag and if there is,
//it doesn't print a newline
void	ft_echo(char **input)
{
	int	i;
	int	n_flag;

	i = 1;
	n_flag = 0;
	if (input[1] != NULL && ft_strcmp(input[1], "-n") == 0)
	{
		n_flag = 1;
		i++;
	}
	while (input[i] != NULL)
	{
		ft_putstr_fd(input[i], STDOUT_FILENO);
		if (input[i + 1] != NULL)
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	if (n_flag == 0)
		ft_putstr_fd("\n", STDOUT_FILENO);
}
