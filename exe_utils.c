/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:39:51 by manujime          #+#    #+#             */
/*   Updated: 2023/06/09 14:10:56 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//checks if the input[0] has "./" before the executable name
//if it does it prints perror(path), if it doesn't it prints
//ft_putstr_fd("command not found", 2)
void	ft_print_error(char *path, int outfd)
{
	dup2(STDOUT_FILENO, outfd);
	if (ft_strnstr(path, "./", 3) != 0 || ft_strnstr(path, "/", 2) != 0)
		perror(path);
	else
	{
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd("command not found \n", STDERR_FILENO);
	}
}
