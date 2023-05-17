/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:14:58 by manujime          #+#    #+#             */
/*   Updated: 2023/05/17 15:22:29 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_builtins(char **input, char **envp)
{
	(void)envp;
	if (ft_strcmp(input[0], "cd") == 0)
		ft_cd(input);
	else if (ft_strcmp(input[0], "pwd") == 0)
		ft_pwd();
	//TODO: add the rest of the builtins
	// else if (ft_strcmp(input[0], "echo") == 0)
	// 	ft_echo(input);
	// else if (ft_strcmp(input[0], "export") == 0)
	// 	ft_export(input, envp);
	// else if (ft_strcmp(input[0], "unset") == 0)
	// 	ft_unset(input, envp);
	// else if (ft_strcmp(input[0], "env") == 0)
	// 	ft_env(envp);
	// else if (ft_strcmp(input[0], "exit") == 0)
	// 	ft_exit(input);
	if (!ft_strcmp(input[0], "cd") || !ft_strcmp(input[0], "pwd"))
		return (1);
	return (0);
}

//Search and launch the right executable (based on the PATH variable or using a
//relative or an absolute path)
void	ft_launch_executable(char **input, int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		status;
	char	*path;

	(void)argc;
	(void)argv;
	path = input[0];
	pid = fork();
	if (pid == 0)
	{
		dup2(STDOUT_FILENO, STDOUT_FILENO);
		dup2(STDERR_FILENO, STDERR_FILENO);
		if (execve(path, input, envp) == -1)
			perror("minishell1");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("minishell2");
	else
	{
		waitpid(pid, &status, WUNTRACED);
	}
}

//this is the main function, it displays a prompt and waits for the user to
//enter a command. It then reads the command and executes it. It loops until
//the user presses ctrl-D or types exit.
int	main(int argc, char *argv[], char *envp[])
{
	char	*input;
	char	**splitted;
	int		builtins;

	while (1)
	{
		builtins = 0;
		input = readline("minishell> ");
		if (input == NULL)
		{
			printf("\n");
			break ;
		}
		add_history(input);
		splitted = ft_split(input, ' ');
		builtins = ft_builtins(splitted, envp);
		if (!builtins)
			ft_launch_executable(splitted, argc, argv, envp);
		free(input);
	}
	return (0);
}
