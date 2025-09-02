/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ack_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:09:59 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/02 18:38:47 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "client.h"
#include <stdio.h>

void	ack_handler(int sig)
{
	(void)sig;
	ack_received = 1;
	//printf("ack_received set to 1\n");
}
