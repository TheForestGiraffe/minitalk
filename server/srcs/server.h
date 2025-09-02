/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:14:05 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/02 19:40:32 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>

typedef struct s_state
{
	volatile sig_atomic_t	bit_received;
	volatile sig_atomic_t	client_pid;
}							t_state;

extern t_state	g_state;

void	sigaction_handler(int sig, siginfo_t *info, void *context);
void	setup_sigaction(void);
void	process_bit(char *c, unsigned int *current_bit);

#endif
