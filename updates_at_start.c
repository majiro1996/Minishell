/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:41:23 by manujime          #+#    #+#             */
/*   Updated: 2023/06/01 13:50:15 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//updates the SHLVL variable
void	ft_shlvl(t_data *data)
{
	int		c;
	char	*tmp;

	c = 0;
	while (data->envp[c])
	{
		if (ft_strcmp("SHLVL", ft_get_var(data->envp[c])) == 0)
		{
			tmp = ft_strjoin("SHLVL=",
					ft_itoa(ft_atoi(data->envp[c] + 6) + 1));
			free(data->envp[c]);
			data->envp[c] = tmp;
			break ;
		}
		c++;
	}
}

//updates the SHELL variable to the path of the executable
//and calls ft_shlvl to update the SHLVL variable
void	ft_shell_name(t_data *data)
{
	int		c;
	char	*aux;
	char	*path;

	c = 0;
	path = getcwd(NULL, 0);
	while (data->envp[c])
	{
		if (ft_strcmp("SHELL", ft_get_var(data->envp[c])) == 0)
		{
			aux = ft_strjoin("SHELL=", path);
			free(path);
			free(data->envp[c]);
			data->envp[c] = aux;
			break ;
		}
		c++;
	}
	ft_shlvl(data);
}
