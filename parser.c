/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:27:37 by manujime          #+#    #+#             */
/*   Updated: 2023/06/22 15:56:17 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//returns the variable value from an environment variable
char	*ft_get_env(char *input, t_data *data)
{
	int		c;
	char	*var;
	char	**value;
	char	*tmp;

	c = 0;
	while (data->envp[c])
	{
		var = ft_get_var(data->envp[c]);
		if (ft_strcmp(var, input) == 0)
		{
			free(var);
			value = ft_split(data->envp[c], '=');
			tmp = ft_strdup(value[1]);
			ft_free_char_matrix(value);
			return (tmp);
		}
		free(var);
		c++;
	}
	return (NULL);
}

//prints the content of the input linked list
//used for debugging only
void	ft_print_input(t_input *list)
{
	while (list)
	{
		printf("content: %s\n", list->content);
		printf("type: %d\n", list->type);
		list = list->next;
	}
}

//counts how big should be the allocated memory for the input char **
int	ft_count_input(t_input *list)
{
	int		count;
	t_input	*tmp;

	tmp = list;
	count = 0;
	while (tmp && tmp->type != 7)
	{
		if (tmp->type == 3 || tmp->type == 4
			|| tmp->type == 5 || tmp->type == 6)
		{
			tmp = tmp->next;
			continue ;
		}
		count++;
		tmp = tmp->next;
	}
	return (count);
}

//parses the line string of the data struct
void	ft_parse(t_data *data)
{
	ft_input_parse(data);
	ft_search_and_replace(data);
	data->pipecount = ft_count_pipes(data->list);
}
