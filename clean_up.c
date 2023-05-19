/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:09:32 by manujime          #+#    #+#             */
/*   Updated: 2023/05/19 12:33:01 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//keep this commented when pushing to the 42 repo
//the leaks produced by readline don't need to be fixed
void	ft_leaks(void)
{
	system("leaks -q minishell");
}

void	ft_clean_input(t_data data)
{
	free(data.line);
	free(data.input);
}
