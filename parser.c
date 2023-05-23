/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:27:37 by manujime          #+#    #+#             */
/*   Updated: 2023/05/23 20:50:44 by manujime         ###   ########.fr       */
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

//counts the number of instances of a character in a string
int	ft_count_char(char *str, char a)
{
	int	c;
	int	k;

	c = 0;
	k = 0;
	while (str[c])
	{
		if (str[c] == a)
			k++;
		c++;
	}
	return (k);
}

//removes all instances of a character from the line string of 
//the data struct
void	ft_remove_char(t_data *data, char a, int count)
{
	int		c;
	int		k;
	int		len;
	char	*new;

	c = 0;
	k = 0;
	len = ft_strlen(data->line) - count;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return ;
	while (data->line[c])
	{
		if (data->line[c] != a)
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

//removes all instances of single quotes from the line string of
//the data struct
void	ft_single_quote(t_data *data)
{
	int		c;
	int		k;
	int		len;
	char	*new;

	c = 0;
	k = 0;
	len = ft_strlen(data->line) - ft_count_char(data->line, '\'');
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return ;
	while (data->line[c])
	{
		if (data->line[c] != '\'')
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
	int		q_count;

	c = 0;
	q_count = ft_count_char(data->line, '\"');
	if (q_count)
		ft_remove_char(data, '\"', q_count);
	ft_single_quote(data);
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
