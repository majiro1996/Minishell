/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:43:08 by manujime          #+#    #+#             */
/*   Updated: 2023/05/29 13:09:10 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

//
void	ft_split_content(t_data *data)
{
	t_input	*aux;

	aux = data->list;
	while (aux->next)
	{
		ft_remove_quotes(data);
		printf("content2: %s\n", aux->content);//
		aux->splitted = ft_split(aux->content, ' ');
		if (aux->type == 0 || aux->type == 2)
		{
			ft_replace_var(aux, data);
			//printf("splitted: \n");//
			//ft_print_char_matrix(aux->splitted);//
		}
		aux = aux->next;
	}
}
