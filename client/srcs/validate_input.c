/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:09:59 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/02 15:56:33 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "client.h"

void	validate_input(int argc, pid_t pid, char *str)
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
