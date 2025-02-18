# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/15 16:53:36 by itsiros           #+#    #+#              #
#    Updated: 2025/02/18 02:00:06 by itsiros          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -O2

# Libft directory
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Source directory
SRC_DIR = src

# Source files
SRC = main.c linked_list.c utils.c errors.c swap.c push.c rotate.c reverse_rotate.c push_swap.c tests.c
SRC := $(addprefix $(SRC_DIR)/, $(SRC))

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

# Rule to clean object files
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

# Rule to clean object files and executable
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rule to rebuild everything
re: fclean $(NAME)

# Rule to build libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

.PHONY: clean fclean re

