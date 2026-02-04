# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/27 12:16:10 by pecavalc          #+#    #+#              #
#    Updated: 2026/02/04 01:58:01 by pecavalc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
	
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS =  server.c \
		setup_sigaction.c \
		sigaction_handler.c \
		process_bit.c
OBJS = $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS))

HEADERS_DIR = srcs
HEADERS = $(HEADERS_DIR)/server.h

LIBFT_DIR = ../Libft-2.1.1
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_HEADERS_DIR = $(LIBFT_DIR)/include
LIBFT_HEADERS = $(LIBFT_HEADERS_DIR)/libft.h

CFLAGS = -Wall -Wextra -Werror -g -I$(HEADERS_DIR) -I$(LIBFT_HEADERS_DIR)

GREEN = \033[0;32m

all: $(NAME)
	@echo "$(GREEN)Build successful $(RESET)"

$(NAME): $(OBJS) $(LIBFT)
	cc $(CFLAGS) -o $@ $^ 

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS)
	mkdir -p $(OBJS_DIR)
	cc $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
