# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 15:14:05 by bkonjuha          #+#    #+#              #
#    Updated: 2020/07/09 14:14:26 by bkonjuha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEMIN = lem-in

SRC_PATH = ./srcs/
SRC_FILES = lemin.c ft_errno.c find_path.c read_rooms.c ft_queuenew.c ft_queueadd.c \
			ft_dequeue.c ft_queueaddfront.c ft_queuefind.c save_path.c printer.c \
			combinations.c checker.c
SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))

INCLUDES = -I ./includes/
HEADER_PATH = ./includes/
HEADER_FILES = lemin.h
HEADERS = $(addprefix $(HEADER_PATH), $(HEADER_FILES))
COMPILE = gcc -Wall -Werror -Wextra -g # DELETE THIS <-----------------------------------------------------------------

LIBFT_PATH = libraries/ft_printf/libft/
LIBFT_FILE = libft.a
LIBFT = $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))
PRINTF_SRCS = libraries/ft_printf/srcs/
PRINTF_PATH = libraries/ft_printf/
PRINTF_FILE = libftprintf.a
PRINTF = $(addprefix $(PRINTF_PATH), $(PRINTF_FILE))

COLOR_RESET = \033[0m
COLOR_PENDING = \033[0;33m
COLOR_SUCCESS = \033[0;32m
COLOR_DEFAULT = \033[1;34m

all: $(LEMIN)

$(LEMIN): $(HEADERS) $(LIBFT) $(PRINTF)
		@$(COMPILE) $(SRC) $(LIBFT) $(PRINTF) -o $(LEMIN)
		@echo "[$(COLOR_PENDING)Putting everything togeather$(COLOR_RESET)]"
		@echo "[$(COLOR_SUCCESS)Executable $(PUSH_SWAP) created$(COLOR_RESET)]"

$(PRINTF) $(LIBFT): $(PRINTF_SRCS)*.c $(LIBFT_PATH)*.c
		@echo "Recompiling libraries"
		@make -C $(PRINTF_PATH)

exec:
		@$(COMPILE) $(SRC) $(LIBFT) $(PRINTF) -o $(LEMIN)
		@echo "[$(COLOR_PENDING)Putting everything togeather$(COLOR_RESET)]"
		@echo "[$(COLOR_SUCCESS)Executable $(PUSH_SWAP) created$(COLOR_RESET)]"

clean:
		@make clean -C libraries/ft_printf/ >/dev/null

fclean: clean
		@rm -fv $(LEMIN) > /dev/null
		@make fclean -C libraries/ft_printf/ >/dev/null

re: fclean all

.PHONY = all clean fclean re
