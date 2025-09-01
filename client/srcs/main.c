/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:09:59 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/01 16:55:40 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "ft_printf.h"
#include "libft.h"

static void	validate_input(int argc, pid_t pid, char *str);
static void	send_message(pid_t pid, char *str);
static void	acknowledgement_handler(int sig, siginfo_t *info, void *context);

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_handler = acknowledgement_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaction(SIGUSR1, &sa, NULL);

	pid = (pid_t)ft_atoi(argv[1]);
	validate_input(argc, pid, argv[2]);
	send_message(pid, argv[2]);
	return (0);
}

static void	validate_input(int argc, pid_t pid, char *str)
{
	if (argc != 3)
	{
		ft_printf("Message not sent. ");
		ft_printf("Expected two arguments: server's PID and a string.\n");
		exit(EXIT_FAILURE);
	}
	if (pid <= 0 || kill(pid, 0) == -1)
	{
		ft_printf("Message not sent. ");
		ft_printf("Invalid PID.\n");
		exit(EXIT_FAILURE);
	}
	if (!str)
	{
		ft_printf("Message not sent. ");
		ft_printf("String pointer NULL.\n");
		exit(EXIT_FAILURE);
	}
}

static void	send_message(pid_t pid, char *str) // TODO: regard ack
{
	int	bit;

	while (true)
	{
		bit = 7;
		while (bit >= 0)
		{
			if (((*str >> bit) & 1) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit--;
			usleep(100);
		}
		if (*str == '\0')
			break ;
		str++;
	}
}
static void	acknowledgement_handler(int sig, siginfo_t *info, void *context)
{
	// TODO
}