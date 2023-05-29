/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:43:08 by manujime          #+#    #+#             */
/*   Updated: 2023/05/29 16:31:58 by manujime         ###   ########.fr       */
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

void	ft_replace_var(t_input *input, t_data *data)
{
	int		c;

	c = 0;
	while (input->splitted[c])
	{
		if (input->splitted[c][0] == '$')
			input->splitted[c] = ft_get_env(input->splitted[c] + 1, data);
		c++;
		//printf("replaced: %s\n", input->splitted[c]);//
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
		aux->splitted = ft_split(aux->content, ' ');
		if (aux->type == 0 || aux->type == 2)
		{
			ft_replace_var(aux, data);
		}
		aux = aux->next;
	}
}
