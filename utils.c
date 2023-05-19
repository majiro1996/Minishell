/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:46:34 by manujime          #+#    #+#             */
/*   Updated: 2023/05/19 18:03:21 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//prints the environment variables
void	ft_print_env(char **envp)
{
	int	c;

	c = 0;
	while (envp[c])
	{
		ft_putstr_fd(envp[c], STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		c++;
	}
}

//adds a new environment variable to the envp array
void	ft_add_env(char *input, char **envp)
{
	static int	first;
	int			c;
	char		**new_envp;

	c = 0;
	while (envp[c])
		c++;
	new_envp = malloc(sizeof(char *) * (c + 2));
	c = 0;
	while (envp[c])
	{
		new_envp[c] = ft_strdup(envp[c]);
		c++;
	}
	new_envp[c] = ft_strdup(input);
	new_envp[c + 1] = NULL;
	envp = new_envp;
	if (first != 0)
		free (envp);
	first++;
}
