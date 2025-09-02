/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:09:59 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/02 19:22:20 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "client.h"
#include <stdio.h>

void	send_message(pid_t pid, char *str)
{
	int	bit;

	while (1)
	{
		bit = 7;
		while (bit >= 0)
		{
			usleep(5);
			g_ack_received = 0;
			if (((*str >> bit) & 1) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (!g_ack_received)
				pause();
			bit--;
		}
		if (*str == '\0')
			break ;
		str++;
	}
}
