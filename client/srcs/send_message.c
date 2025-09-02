/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:09:59 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/02 18:48:13 by pecavalc         ###   ########.fr       */
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
			ack_received = 0;
			if (((*str >> bit) & 1) == 0)
			{	
				kill(pid, SIGUSR1);
				//printf("SIGUSR1 sent.\n");
			}
			else
			{
				//printf("SIGUSR2 sent.\n");
				kill(pid, SIGUSR2);
			}
			while (!ack_received)
			{
				//printf("Pausing next...\n");				
				pause();
				//printf("Signal received. Out of pause - resumed.\n");
			}
			bit--;
			//printf("bit: %i\n", bit);
		}
		if (*str == '\0')
		{
			//printf("end found, breaking next...");
			break ;
		}
		str++;
	}
}
