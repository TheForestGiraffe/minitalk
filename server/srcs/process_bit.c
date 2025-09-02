/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:03:19 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/02 19:33:08 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "server.h"

void	process_bit(char *c, unsigned int *current_bit)
{
	pause();
	*c <<= 1;
	if (g_state.bit_received)
		*c |= 1;
	(*current_bit)++;
	if (*current_bit == 8)
	{
		if (*c == '\0')
			write(1, "\n", 1);
		else
			write(1, c, 1);
		*c = 0;
		*current_bit = 0;
	}
	usleep(5);
	kill(g_state.client_pid, SIGUSR1);
}
