/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:14:27 by manujime          #+#    #+#             */
/*   Updated: 2023/05/26 00:18:48 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//sets the type of the input node
//0 = non-quoted string
//1 = single quoted string
//2 = double quoted string
void	ft_set_input_type(t_data *data)
{
	t_input	*tmp;

	tmp = data->list;
	while (tmp)
	{
		if (tmp->content[0] == '\''
			&& tmp->content[ft_strlen(tmp->content) - 1] == '\'')
			tmp->type = 1;
		else if (tmp->content[0] == '\"'
			&& tmp->content[ft_strlen(tmp->content) - 1] == '\"')
			tmp->type = 2;
		else
			tmp->type = 0;
		printf("content: %s type: %d\n", tmp->content, tmp->type);//TODO: remove this line
		tmp = tmp->next;
	}
}

//creates a new node and adds it to the end of the list
//the node contains from s to e of the data->line string
void	ft_new_node(t_data *data, int s, int e)
{
	t_input	*new;
	t_input	*tmp;
	char	*str;

	str = ft_substr(data->line, s, e - s);
	new = malloc(sizeof(t_input));
	if (!new)
		return ;
	new->content = str;
	new->type = 0;
	new->next = NULL;
	if (!data->list)
		data->list = new;
	else
	{
		tmp = data->list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

//handles the quoted part of the input string
//separating it into a new node for further processing later
void	ft_quote_node(t_data *data, int *start, int *counter, char quote)
{
	int	c;
	int	s;

	c = *counter;
	s = *start;
	c++;
	while (data->line[c] && data->line[c] != quote)
		c++;
	if (data->line[c] == quote)
		c++;
	ft_new_node(data, s, c);
	*counter = c;
}

//divides the data->line string into nodes
//each node contains a string surrounded by single or double quotes
//or a non-quoted string, that includes non closed quotes
void	ft_input_parse(t_data *data)
{
	int	c;
	int	s;

	c = 0;
	while (data->line[c])
	{
		s = c;
		if (data->line[c] == '\'')
			ft_quote_node(data, &s, &c, '\'');
		else if (data->line[c] == '\"')
			ft_quote_node(data, &s, &c, '\"');
		else
		{
			while (data->line[c] && data->line[c] != '\''
				&& data->line[c] != '\"')
				c++;
			ft_new_node(data, s, c);
		}
	}
	ft_set_input_type(data);
}
