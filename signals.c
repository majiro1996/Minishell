/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgonza <albgonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:02:07 by albgonza          #+#    #+#             */
/*   Updated: 2023/05/23 19:46:55 by albgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handler(int signal, siginfo_t *info, void *uap)
{
	(void)uap;
	if (signal == SIGINT)
	{
		kill(info->si_pid, SIGINT);
	}
}

void	signal_setter(void)
{
	struct sigaction	sa;
	struct sigaction	sa_ignore;

	sa.sa_sigaction = &signal_handler;
	sa_ignore.sa_handler = SIG_IGN;
	sigemptyset(&sa_ignore.sa_mask);
	sa_ignore.sa_flags = 0;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGQUIT, &sa_ignore, NULL);
	sigaction(SIGINT, &sa, NULL);
}
