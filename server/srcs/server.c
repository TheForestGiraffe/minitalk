/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:03:19 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/02 19:33:44 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "ft_printf.h"
#include "server.h"

t_state	g_state = {0, 0};

int	main(void)
{
	char			c;
	unsigned int	current_bit; 

	setup_sigaction();
	ft_printf("Server's PID: %i\n", getpid());
	c = 0;
	current_bit = 0;
	while (1)
		process_bit(&c, &current_bit);
	return (0);
}
