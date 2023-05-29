/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:43:08 by manujime          #+#    #+#             */
/*   Updated: 2023/05/29 18:08:48 by manujime         ###   ########.fr       */
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

//takes the variable name afther the $ and replaces it with its value
//if the variable is not found, it is replaced with an empty string
void	ft_replace_var(t_input *input)
{
	if (input->type == 1)
		return ;
	if (ft_strchr(input->content, '$'))
	{
		printf("there is a $ in %s\n", input->content);//debug//
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
		if (aux->type == 0 || aux->type == 2)
		{
			ft_replace_var(aux);
		}
		aux = aux->next;
	}
}
