/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:14:58 by manujime          #+#    #+#             */
/*   Updated: 2023/05/15 19:01:58 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Search and launch the right executable (based on the PATH variable or using a
//relative or an absolute path)
void	ft_launch_executable(char **input, int argc, char *argv[], char *envp[])
{
	pid_t	pid;
	int		status;

	(void)argc;
	pid = fork();
	if (pid == 0)
	{
		if (execve(input[0], argv, envp) == -1)
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
	char	*input;
	char	**parsed;

	while (1)
	{
		input = readline("minishell> ");
		if (input == NULL)
		{
			printf("\n");
			break ;
		}
		add_history(input);
		parsed = ft_split(input, ' ');
		ft_launch_executable(parsed, argc, argv, envp);
		free(input);
	}
	return (0);
}
