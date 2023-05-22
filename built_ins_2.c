/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:41:29 by manujime          #+#    #+#             */
/*   Updated: 2023/05/22 20:28:06 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//checks if the var to remove exits
int	ft_unset_check(t_data *data)
{
	char	*var;
	int		c;
	int		found;

	c = 0;
	found = 0;
	while (data->envp[c])
	{
		var = ft_get_var(data->envp[c]);
		if (ft_strcmp(var, data->input[1]) == 0)
		{
			free(var);
			found = 1;
		}
		c++;
	}
	return (found);
}

//removes a variable from the envp array
void	ft_unset(t_data *data)
{
	char	*var;
	char	**new_envp;
	int		c;

	if (ft_unset_check(data) == 0)
		return ;
	c = 0;
	new_envp = malloc(sizeof(char *) * (c));
	while (data->envp[c])
	{
		var = ft_get_var(data->envp[c]);
		if (ft_strcmp(var, data->input[1]) == 0)
		{
			free(var);
			c++;
			continue ;
		}
		new_envp[c] = ft_strdup(data->envp[c]);
		c++;
	}
	new_envp[c - 1] = NULL;
	ft_free_char_matrix(data->envp);
	data->envp = new_envp;
}
