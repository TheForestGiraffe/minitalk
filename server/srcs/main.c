/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:03:19 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/01 22:59:34 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ft_printf.h"

typedef struct	s_state
{
	unsigned char	character;
	unsigned int	bit;
	pid_t			client_pid;
}					t_state;

static t_state	current = {0, 0, 0};

static void	handler(int sig, siginfo_t *info, void *context);

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	// Specify within sa the function that will handle the signal
	sa.sa_sigaction = handler;
	
	// Specify that handler will be called with 3 args - needed for sigaction
	sa.sa_flags = SA_SIGINFO;

	// Atomic handling:
	//  1. Clear the mask: remove all signals from the mask (in case of garbage)
	sigemptyset(&sa.sa_mask);
	//  2. Add signals to the mask
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);

	// Register which handler will be called depending on the type of signal received
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	pid = getpid();
	ft_printf("Server's PID: %i\n", pid);

	while (true)
		pause();
		
	return (0);
}

static void	handler(int sig, siginfo_t *info, void *context)
{
	unsigned int	clear_client_pid;
	
	(void)context;
	if (current.client_pid == 0)
		current.client_pid = info->si_pid;
	if (current.client_pid != info->si_pid)
		return ;
	current.character <<= 1;
	if (sig == SIGUSR2)
		current.character |= 1;
	current.bit++;
	clear_client_pid = 0;
	if (current.bit == 8)
	{
		if (current.character == '\0')
		{
			write(1, "\n", 1);
			clear_client_pid = 1;
		}
		else
			write(1, &current.character, 1);
		current.bit = 0;
		current.character = 0;
	}

	if (clear_client_pid)
		current.client_pid = 0;
		
	// Send acknowledgement to client after fully processing the data
	kill(info->si_pid, SIGUSR1);
}
