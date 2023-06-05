/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:04:55 by manujime          #+#    #+#             */
/*   Updated: 2023/06/05 13:06:15 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//counts the number of pipes in the input linked list
int	ft_count_pipes(t_input *list)
{
	int		count;
	t_input	*tmp;

	tmp = list;
	count = 0;
	while (tmp)
	{
		if (tmp->type == 7)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

void	ft_multiple_commands(t_data *data, int *builtins)
{
	data->current = data->list;
	while (data->current)
	{
		data->input = ft_split(ft_full_join(data->current), ' ');
		*builtins = ft_builtins(data);
		if (!builtins && data->input[0])
			ft_launch_executable(data);
		ft_free_char_matrix(data->input);
		while (data->current && data->current->type != 7)
			data->current = data->current->next;
		if (data->current && data->current->type == 7)
			data->current = data->current->next;
	}
}
