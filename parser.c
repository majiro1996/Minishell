/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgonza <albgonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:27:37 by manujime          #+#    #+#             */
/*   Updated: 2023/05/30 17:14:53 by albgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	**ft_parse(t_data *data)
{
	char	**input;
	int		c;

	c = 0;
	input = ft_split(data->line, ' ');
	while (input[c])
	{
		if (input[c][0] == '$')
		{
			if (input[c][1] == '?')
			{
				printf("%d\n", *(data->actual_status));
				// input[c] = ft_itoa(*(data->actual_status));
			}
			else
				input[c] = ft_get_env(input[c] + 1, data);
		}
		c++;
	}
	return (input);
}
