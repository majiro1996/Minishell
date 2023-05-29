/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgonza <albgonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:12:32 by manujime          #+#    #+#             */
/*   Updated: 2023/05/23 19:42:41 by albgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_data(t_data *data, int argc, char **argv, char **envp)
{
	data = malloc(sizeof(t_data));
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	data->actual_status = malloc(sizeof(int));
	signal_setter();
}
