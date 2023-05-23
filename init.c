/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:12:32 by manujime          #+#    #+#             */
/*   Updated: 2023/05/23 13:58:37 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//copies the envp to the data structure
//this makes it easier to update the environment variables
void	ft_copy_envp(t_data *data, char **envp)
{
	int	c;

	c = 0;
	while (envp[c])
		c++;
	data->envp = malloc(sizeof(char *) * (c + 1));
	if (!data->envp)
		perror("malloc error");
	c = 0;
	while (envp[c])
	{
		data->envp[c] = ft_strdup(envp[c]);
		c++;
	}
	data->envp[c] = NULL;
}

//initializes the data structure
void	ft_init_data(t_data *data, int argc, char **argv, char **envp)
{
	data->argc = argc;
	data->argv = argv;
	ft_copy_envp(data, envp);
}
