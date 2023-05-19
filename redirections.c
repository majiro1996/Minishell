/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgonza <albgonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:23:18 by marvin            #+#    #+#             */
/*   Updated: 2023/05/19 20:13:18 by albgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_output(int append_flag, char **input)
{
	// FILE	*file;
	char	*filename;
	// int		devnull;
	(void)append_flag;

	filename = input[0];
	printf("%s\n", filename);
	// if (!append_flag)
	// 	file = freopen(filename, "w+", stdout);
	// else
	// 	file = freopen(filename, "a+", stdout);
	// if (file == NULL)
	// 	printf("stdout error: %s\n", strerror(2));
	// devnull = open("/dev/null", O_WRONLY);
	// dup2(devnull, 1);
	// close(devnull);
	// fclose(file);
}
