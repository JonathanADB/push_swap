# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/08 14:41:46 by jonadomi          #+#    #+#              #
#    Updated: 2026/02/02 21:13:33 by jonadomi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iinclude -I$(LIBFT_DIR)/include
RM          = rm -f

SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = include
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

# Encuentra todos los .c dentro de src y subcarpetas
SRCS        = $(shell find $(SRC_DIR) -name "*.c")

# Convierte src/xxx.c → obj/xxx.o
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Header principal
HEADER      = $(INC_DIR)/push_swap.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT): 
	$(MAKE) -C $(LIBFT_DIR)

# Compila .o y crea subcarpetas automáticamente
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
