/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:41:45 by manujime          #+#    #+#             */
/*   Updated: 2023/05/18 18:58:48 by manujime         ###   ########.fr       */
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
	int	c;
	int	n_flag;

	c = 1;
	n_flag = 0;
	if (input[1] && ft_strcmp(input[1], "-n") == 0)
	{
		n_flag = 1;
		c++;
	}
	while (input[c])
	{
		ft_putstr_fd(input[c], STDOUT_FILENO);
		if (input[c + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		c++;
	}
	if (n_flag == 0)
		ft_putstr_fd("\n", STDOUT_FILENO);
}

//checks if there is an argument, if there is, it checks if it's valid
//then exits with the argument as the exit code
//if there is no argument, it exits with the exit code 0
void	ft_exit(char **input)
{
	int	c;

	c = 0;
	while (input[c])
		c++;
	if (c == 1)
		exit(EXIT_SUCCESS);
	else if (c == 2)
	{
		if (ft_isdigit(input[1][0]) == 1)
			exit(ft_atoi(input[1]));
		else
		{
			printf("exit: %s", strerror(2));
			printf(": %s\n", input[1]);
			exit(2);
		}
	}
	else
	{
		printf("exit: too many arguments\n");
		exit(1);
	}
}
