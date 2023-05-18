/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:14:58 by manujime          #+#    #+#             */
/*   Updated: 2023/05/18 15:42:39 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//checks if the first argument is a builtin command and if it is, executes it
//and returns 1, if it isn't, returns 0
int	ft_builtins(char **input, char **envp)
{
	(void)envp;
	if (ft_strcmp(input[0], "cd") == 0)
		ft_cd(input);
	else if (ft_strcmp(input[0], "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(input[0], "echo") == 0)
		ft_echo(input);
	//TODO: add the rest of the builtins
	// else if (ft_strcmp(input[0], "export") == 0)
	// 	ft_export(input, envp);
	// else if (ft_strcmp(input[0], "unset") == 0)
	// 	ft_unset(input, envp);
	// else if (ft_strcmp(input[0], "env") == 0)
	// 	ft_env(envp);
	// else if (ft_strcmp(input[0], "exit") == 0)
	// 	ft_exit(input);
	if (!ft_strcmp(input[0], "cd") || !ft_strcmp(input[0], "pwd")
		|| !ft_strcmp(input[0], "echo"))
		return (1);
	return (0);
}

//Search and launch the right executable (based on the PATH variable or using a
//relative or an absolute path)
void	ft_launch_executable(t_data data)
{
	pid_t	pid;
	int		status;
	char	*path;

	path = data.input[0];
	pid = fork();
	if (pid == 0)
	{
		dup2(STDOUT_FILENO, STDOUT_FILENO);
		dup2(STDERR_FILENO, STDERR_FILENO);
		if (execve(path, data.input, data.envp) == -1)
			perror("minishell");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("minishell");
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
	int		builtins;
	t_data	data;

	ft_init_data(&data, argc, argv, envp);
	while (1)
	{
		builtins = 0;
		data.line = readline("minishell> ");
		if (data.line == NULL)
		{
			printf("\n");
			break ;
		}
		if (ft_strcmp(data.line, "") == 0)
			continue ;
		add_history(data.line);
		data.input = ft_split(data.line, ' ');
		builtins = ft_builtins(data.input, envp);
		if (!builtins && data.input[0])
			ft_launch_executable(data);
		ft_clean_input(data);
	}
	return (0);
}
