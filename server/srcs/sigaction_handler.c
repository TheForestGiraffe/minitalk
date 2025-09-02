/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigaction_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:03:19 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/02 18:42:40 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "server.h"
#include <stdio.h>

void	sigaction_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	// printf("signal received.\n");
	if (sig == SIGUSR1)
	{
		state.bit_received = 0;
		// rintf("bit_received = 0\n");
	}
	if (sig == SIGUSR2)
	{
		state.bit_received = 1;
		// printf("bit_received = 1\n");
	}
	state.client_pid = info->si_pid;
}
