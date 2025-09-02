/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:03:19 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/02 18:48:20 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h> 			 	  // Silence IntelliSense for pid_t
#include <asm-generic/signal-defs.h>  // Silense IntelliSense for SA_SIGINFO
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "server.h"
#include <stdio.h>

t_state state = {0, 0};

int	main(void)
{
	char			c;
	unsigned int	current_bit; 

	// printf("setting up sigaction\n");
	setup_sigaction();
	ft_printf("Server's PID: %i\n", getpid());
	c = 0;
	current_bit = 0;
	// printf("while comes next\n");
	while (1)
	{
		// printf("Pausing next...\n");
		pause();
		// printf("resumed while...\n");
		c <<= 1;
		if (state.bit_received)
			c |= 1;
		current_bit++;
		if (current_bit == 8)
		{
			if (c == '\0')
				write(1, "\n", 1);
			else
			{
				// write(1, "-----\n", 6);
				write(1, &c, 1);
				// write(1, "\n-----\n", 7);
			}

			c = 0;
			current_bit = 0;
		}
		usleep(5);
		kill(state.client_pid, SIGUSR1);
		// printf("sent signal back to client.\n");
	}
	return (0);
}
