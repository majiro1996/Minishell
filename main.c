/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:14:58 by manujime          #+#    #+#             */
/*   Updated: 2023/06/09 15:13:06 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//checks if the first argument is a builtin command and if it is, executes it
//and returns 1, if it isn't, returns 0
int	ft_builtins(t_data *data, int inputfd, int outputfd)
{	
	pid_t	pid;
	int		status;
	int		is_builtin;

	is_builtin = 0;
	if (ft_strnstr("cd pwd echo exit export unset env",
			data->input[0], 33) != 0)
		is_builtin = 1;
	if (is_builtin == 1 && ft_strnstr("pwd echo env",
			data->input[0], 33) != 0)
	{
		pid = fork();
		if (pid == 0)
			ft_execute_builtin(data, inputfd, outputfd);
		else if (pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else
			waitpid(pid, &status, WUNTRACED);
	}
	return (is_builtin);
}

//checks if the first argument exists in the path from the PATH variable
//and if it does, it replaces the first argument with the full path
//to the executable
void	ft_execute_from_path(t_data *data)
{
	char	*path;
	char	*exec;
	char	**paths;
	int		c;

	path = ft_get_env("PATH", data);
	paths = ft_split(path, ':');
	c = 0;
	while (paths[c])
	{
		exec = ft_strjoin(paths[c], "/");
		free (paths[c]);
		paths[c] = ft_strjoin(exec, data->input[c]);
		free (exec);
		if (access(*paths, F_OK) == 0)
		{
			free(data->input[0]);
			data->input[0] = ft_strdup(paths[c]);
			break ;
		}
		paths++;
	}
	free (path);
	ft_clean_paths(paths);
}

//Search and launch the right executable (based on the PATH variable or using a
//relative or an absolute path)

void	ft_launch_executable(t_data *data, int infd, int outfd)
{
	int		status;
	char	*path;

	ft_execute_from_path(data);
	path = data->input[0];
	data->child = fork();
	if (data->child == 0)
	{
		ft_redirect_in_out(infd, outfd);
		if (execve(path, data->input, data->envp) == -1)
			ft_print_error(path, outfd);
		ft_clean_exit(EXIT_FAILURE, data);
	}
	else if (data->child < 0)
		perror(path);
	else
	{
		waitpid(data->child, &status, WUNTRACED);
		if (data->child > 0)
		{
			if (WIFEXITED(status))
				data->actual_status = WEXITSTATUS(status);
		}
	}
}

//checks if the first argument is a builtin command and if it isn't, it checks
//if it is an executable and if it is, it executes it
//checks for the exit command and exits the shell if it is
void	ft_command(t_data *data, int inputfd, int outputfd)
{
	int	builtin;

	ft_parent_command(data);
	builtin = ft_builtins(data, inputfd, outputfd);
	if (!builtin && data->input[0])
		ft_launch_executable(data, inputfd, outputfd);
}

//this is the main function, it displays a prompt and waits for the user to
//enter a command. It then reads the command and executes it. It loops until
//the user presses ctrl-D or types exit.
// atexit(ft_leaks);
int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	ft_init_data(&data, argc, argv, envp);
	ft_shell_name(&data);
	while (1)
	{
		data.line = readline("minishell> ");
		if (data.line == NULL)
		{
			printf("\n");
			break ;
		}
		if (ft_strcmp(data.line, "") == 0 || ft_is_all_space(data.line))
			continue ;
		add_history(data.line);
		ft_parse(&data);
		ft_pipeline(&data, ft_count_pipes(data.list));
		ft_clean_input(&data);
	}
	rl_clear_history();
	return (0);
}
