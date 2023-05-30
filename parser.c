/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:27:37 by manujime          #+#    #+#             */
/*   Updated: 2023/05/30 21:49:25 by manujime         ###   ########.fr       */
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
// void	ft_remove_char(t_data *data, int delete)
// {
// 	int		c;
// 	int		k;
// 	char	*new;

// 	c = 0;
// 	k = 0;
// 	new = malloc(sizeof(char) * ft_strlen(data->list->content));
// 	if (!new)
// 		return ;
// 	while (data->list->content[c])
// 	{
// 		if (c != delete)
// 		{
// 			new[k] = data->line[c];
// 			k++;
// 		}
// 		c++;
// 	}
// 	new[k] = '\0';
// 	free(data->list->content);
// 	data->list->content = new;
// }

//joins all the content strings of the input linked list
//into a single string and returns it
char	*ft_full_join(t_input *list)
{
	char	*new;
	char	*tmp;

	new = ft_strdup("");
	while (list)
	{
		tmp = ft_strjoin(new, list->content);
		free(new);
		new = tmp;
		list = list->next;
	}
	return (new);
}

//parses the line string of the data struct
//if 
void	ft_parse(t_data *data)
{
	char	**input;
	char	*tmp;

	ft_input_parse(data);
	ft_search_and_replace(data);
	tmp = ft_full_join(data->list);
	//printf("new: %s\n", tmp);
	input = ft_split(tmp, ' ');//
	//printf("tmp: %s\n", tmp);
	//ft_print_char_matrix(input);
	if (!input)
		return ;
	data->input = input;
	free(tmp);
}
