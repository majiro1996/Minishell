/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:27:37 by manujime          #+#    #+#             */
/*   Updated: 2023/05/25 23:14:28 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//returns the variable value from an environment variable
char	*ft_get_env(char *input, t_data *data)
{
	int		c;
	char	*var;
	char	**value;

	c = 0;
	while (data->envp[c])
	{
		var = ft_get_var(data->envp[c]);
		if (ft_strcmp(var, input) == 0)
		{
			free(var);
			value = ft_split(data->envp[c], '=');
			free (value[0]);
			return (value[1]);
		}
		c++;
	}
	return (NULL);
}

//removes the character in the delete position of the data->line string
void	ft_remove_char(t_data *data, int delete)
{
	int		c;
	int		k;
	char	*new;

	c = 0;
	k = 0;
	new = malloc(sizeof(char) * ft_strlen(data->line));
	if (!new)
		return ;
	while (data->line[c])
	{
		if (c != delete)
		{
			new[k] = data->line[c];
			k++;
		}
		c++;
	}
	new[k] = '\0';
	free(data->line);
	data->line = new;
}

//parses the line string of the data struct
//if 
void	ft_parse(t_data *data)
{
	char	**input;
	int		c;

	c = 0;
	ft_input_parse(data);
	input = ft_split(data->line, ' ');
	if (!input)
		return ;
	while (input[c])
	{
		if (input[c][0] == '$')
			input[c] = ft_get_env(input[c] + 1, data);
		c++;
	}
	data->input = input;
}
