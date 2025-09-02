/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_sigaction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:03:19 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/02 15:34:02 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h> 			 	  // Silence IntelliSense for pid_t
#include <asm-generic/signal-defs.h>  // Silense IntelliSense for SA_SIGINFO
#include <signal.h>
#include <stdlib.h>					  // For NULL
#include "server.h"

void setup_sigaction(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sigaction_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}
