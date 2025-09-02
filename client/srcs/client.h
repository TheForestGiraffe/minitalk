/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:06:35 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/02 15:55:20 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>

extern volatile sig_atomic_t	ack_received;

void	validate_input(int argc, pid_t pid, char *str);
void	send_message(pid_t pid, char *str);
void	ack_handler(int sig);

#endif