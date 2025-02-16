# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/15 16:53:36 by itsiros           #+#    #+#              #
#    Updated: 2025/02/16 02:18:15 by itsiros          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -O2

# Libft directory
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Source files
SRC = src/main.c src/linked_list.c src/utils.c src/errors.c src/swap.c src/push.c

# Object files
OBJ = $(SRC:.c=.o)

# Executable name
NAME = push_swap

# Rule to build the executable
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Rule to clean object files and executable
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rule to rebuild everything
re: fclean $(NAME)

# Phony targets
.PHONY: all clean fclean re

# Default target
all: $(NAME)

