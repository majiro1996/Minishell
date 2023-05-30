/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:43:08 by manujime          #+#    #+#             */
/*   Updated: 2023/05/30 14:32:17 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//removes the first and last character the list->content string
void	ft_remove_quotes(t_input *list)
{
	int		c;
	int		k;
	char	*new;

	c = 1;
	k = 0;
	new = malloc(sizeof(char) * ft_strlen(list->content));
	if (!new)
		return ;
	while (list->content[c])
	{
		new[k] = list->content[c];
		k++;
		c++;
	}
	new[k - 1] = '\0';
	free(list->content);
	list->content = new;
}

void	ft_rep_lace(t_input *input, int s, int e, char *val)
{
	int		c;
	int		k;
	char	*new;

	c = 0;
	k = 0;
	printf("s: %d\n", s);
	printf("e: %d\n", e);
	new = malloc(sizeof(char) * (ft_strlen(input->content)
				- (e - s) + ft_strlen(val) + 1));
	if (!new)
		return ;
	while (c < s)
		new[k++] = input->content[c++];
	c = 0;
	while (val[c])
		new[k++] = val[c++];
	c = e + 1;
	while (input->content[c])
		new[k++] = input->content[c++];
	new[k] = '\0';
	free(input->content);
	input->content = new;
	printf("new: %s\n", new);
}

//takes the position of the first and las character of the variable name
//makes a substring of the variable name
//searches for the variable name in the env list
//if it finds it, it replaces the variable name with the value
void	ft_replace_var(t_input *input, t_data *data)
{
	int		s;
	int		e;
	char	*var;
	char	*val;

	s = 0;
	e = 0;
	while (input->content[e] && input->content[e] != '$')
		e++;
	if (input->content[e] == '$')
	{
		s = e + 1;
		while (input->content[e]
			&& ft_strchr("\"\' $<>|", input->content[e]) == NULL)
			e++;
		var = ft_substr(input->content, s, e - s);
		val = ft_get_env(var, data);
		if (val)
			ft_rep_lace(input, s - 1, s + ft_strlen(var), val);
		free(var);
		free(val);
	}
}

//split the content of each input node
//removes the closed quotes and if the node if of type 0 or 2,
//replaces the variables with their values
void	ft_split_content(t_data *data)
{
	t_input	*aux;

	aux = data->list;
	while (aux)
	{
		if (aux->type == 1 || aux->type == 2)
			ft_remove_quotes(aux);
		printf("non-quoted: %s\n", aux->content);//debug//
		if ((aux->type == 0 || aux->type == 2))
		{
			ft_replace_var(aux, data);
		}
		aux = aux->next;
	}
}
