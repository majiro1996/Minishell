/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:46:34 by manujime          #+#    #+#             */
/*   Updated: 2023/05/22 12:33:44 by manujime         ###   ########.fr       */
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
char	**ft_add_env(char *input, char **envp)
{
	static int	first;
	int			c;
	char		**new_envp;

	c = 0;
	while (envp[c])
		c++;
	new_envp = malloc(sizeof(char *) * (c + 2));
	if (new_envp == NULL)
	{
		ft_putstr_fd("Error: malloc failed\n", STDERR_FILENO);
		return (NULL);
	}
	c = -1;
	while (envp[++c])
		new_envp[c] = ft_strdup(envp[c]);
	new_envp[c] = ft_strdup(input);
	new_envp[c + 1] = NULL;
	envp = new_envp;
	if (first != 0)
		ft_free_char_matrix(envp);
	first++;
	return (envp);
}
