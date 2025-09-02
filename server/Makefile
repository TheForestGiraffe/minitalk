# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/27 12:16:10 by pecavalc          #+#    #+#              #
#    Updated: 2025/09/02 15:31:21 by pecavalc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
	
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS =  server.c \
		setup_sigaction.c \
		sigaction_handler.c
OBJS = $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS))

HEADERS_DIR = srcs
HEADERS = $(HEADERS_DIR)/server.h

LIBFT_DIR = ../../Libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_HEADERS_DIR = $(LIBFT_DIR)/include
LIBFT_HEADERS = $(LIBFT_HEADERS_DIR)/libft.h $(LIBFT_HEADERS_DIR)/libft_bonus.h

PRINTF_DIR = ../../ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
PRINTF_HEADER_DIR = $(PRINTF_DIR)/include
PRINTF_HEADER = $(PRINTF_HEADERS_DIR)/ft_printf.h

CFLAGS = -Wall -Wextra -Werror -g -I$(HEADERS_DIR) -I$(LIBFT_HEADERS_DIR) \
								  -I$(PRINTF_HEADER_DIR)

GREEN = \033[0;32m

all: $(NAME)
	@echo "$(GREEN)Build successful $(RESET)"

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	cc $(CFLAGS) -o $@ $^ 

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS)
	mkdir -p $(OBJS_DIR)
	cc $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) bonus -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
