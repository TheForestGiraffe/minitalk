# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/27 12:16:10 by pecavalc          #+#    #+#              #
#    Updated: 2025/09/01 13:59:47 by pecavalc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
	
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS =  main.c 
OBJS = $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS))

LIBFT_DIR = ../../Libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_HEADERS_DIR = $(LIBFT_DIR)/include
LIBFT_HEADERS = $(LIBFT_HEADERS_DIR)/libft.h $(LIBFT_HEADERS_DIR)/libft_bonus.h

PRINTF_DIR = ../../ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
PRINTF_HEADER_DIR = $(PRINTF_DIR)/include
PRINTF_HEADER = $(PRINTF_HEADER_DIR)/ft_printf.h

CFLAGS = -Wall -Wextra -Werror -g -I$(LIBFT_HEADERS_DIR) \
								  -I$(PRINTF_HEADER_DIR)

GREEN = \033[0;32m

all: $(NAME)
	@echo "$(GREEN)Build successful $(RESET)"

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	cc $(CFLAGS) -o $@ $^ 

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	cc $(CFLAGS) -c $< -o $@

$(LIBFT): $(LIBFT_HEADERS)
	$(MAKE) bonus -C $(LIBFT_DIR)

$(PRINTF): $(PRINTF_HEADER)
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
