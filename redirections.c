/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:23:18 by marvin            #+#    #+#             */
/*   Updated: 2023/05/17 23:23:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    redirect_output(int append_flag, char **input)
{
    FILE    *file;
    char    *filename;
    int     devnull;
    char    **substr;

    puts("a");
    substr = ft_split(input[2], '>');
    filename = ft_strtrim(substr[2], " ");
    puts(filename);
    free(substr);
    devnull = open("/dev/null", O_WRONLY);
    dup2(devnull, 1);
    dup2(devnull, 2);
    close(devnull);
    if (!append_flag)
        file = freopen(filename, "w+", stdout);
    else
        file = freopen(filename, "a+", stdout);
    if (file == NULL)
        printf("stdout error: %s\n", strerror(2));
    fclose(file);
}