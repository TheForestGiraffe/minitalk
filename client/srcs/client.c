/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:09:59 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/02 19:21:51 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"
#include "client.h"

volatile sig_atomic_t	g_ack_received = 0;

int	main(int argc, char **argv)
{
	pid_t				pid;

	signal(SIGUSR1, ack_handler);
	pid = (pid_t)ft_atoi(argv[1]);
	validate_input(argc, pid, argv[2]);
	send_message(pid, argv[2]);
	return (0);
}
