/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:09:32 by manujime          #+#    #+#             */
/*   Updated: 2023/05/29 13:33:25 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//keep this commented when pushing to the 42 repo
//the leaks produced by readline don't need to be fixed
void	ft_leaks(void)
{
	system("leaks -q minishell");
}

void	ft_clean_list(t_input *list)
{
	t_input	*tmp;

	tmp = list;
	while (tmp)
	{
		free(tmp->content);
		free(tmp->splitted);
		tmp = tmp->next;
	}
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	list = NULL;
}

void	ft_clean_input(t_data *data)
{
	t_input	*tmp;

	tmp = data->list;
	free(data->line);
	free(data->input);
	ft_clean_list(tmp);
}
