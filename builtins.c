/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:41:45 by manujime          #+#    #+#             */
/*   Updated: 2023/06/05 23:46:44 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//changes the current directory to the one specified in the input
//if no input is specified, it changes the current directory to the home
//directory
void	ft_cd(t_data *data)
{
	char	*aux;

	aux = data->input[1];
	data->input[1] = ft_strjoin("OLDPWD=", getcwd(NULL, 0));
	ft_update_env(data);
	if (aux == NULL)
	{
		if (chdir(getenv("HOME")) != 0)
			perror("cd");
	}
	else if (chdir(aux) != 0)
	{
		printf("cd: %s", strerror(2));
		printf(": %s\n", aux);
	}
	data->input[1] = ft_strjoin("PWD=", getcwd(NULL, 0));
	ft_update_env(data);
}

//gets the curent working directory and prints it to stdout
//if an error occurs, it prints the error to stderr
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
void	ft_exit(char **input, t_data *data)
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
			ft_clean_input(data);
			exit(2);
		}
	}
	else
	{
		printf("exit: too many arguments\n");
		exit(1);
	}
}

//export command, if there is no argument, it prints the environment
//if there is one argument, it checks if it's valid and if it is, it updates
//the environment variable if it exists, if it doesn't, it adds it to the
//environment
void	ft_export(t_data *data)
{
	int	c;

	c = 0;
	while (data->input[c])
		c++;
	if (c == 1)
		ft_print_env(data->envp);
	else if (c == 2)
	{
		if (ft_isalpha(data->input[1][0]) == 1)
		{
			if (!ft_update_env(data))
				ft_add_env(data);
		}
		else
		{
			printf("export: %s", strerror(2));
			printf(": %s\n", data->input[1]);
		}
	}
	else
	{
		printf("export: too many arguments\n");
	}
}
