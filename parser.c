/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:27:37 by manujime          #+#    #+#             */
/*   Updated: 2023/06/06 18:28:53 by manujime         ###   ########.fr       */
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

//prints the content of the input linked list
void	ft_print_input(t_input *list)///////
{
	while (list)
	{
		printf("content: %s\n", list->content);
		printf("type: %d\n", list->type);
		list = list->next;
	}
}

//joins all the content of the input linked list between pipes
//creating a new string for each command
//
char	*ft_full_join(t_input *list)
{
	char	*new;
	char	*tmp;

	new = ft_strdup("");
	while (list && list->type != 7)
	{
		tmp = ft_strjoin(new, list->content);
		free(new);
		new = tmp;
		list = list->next;
	}
	return (new);
}

//parses the line string of the data struct
void	ft_parse(t_data *data)
{
	ft_input_parse(data);
	ft_search_and_replace(data);
	data->pipecount = ft_count_pipes(data->list);
}
