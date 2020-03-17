# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 12:17:08 by bkonjuha          #+#    #+#              #
#    Updated: 2020/02/20 18:35:35 by bkonjuha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PATH = ./srcs/
SRCS_FILES = ft_printf.c flag_reader.c buffer.c flag_handler.c float_helpers.c floats.c helper.c \
				numbers.c text.c number_helpers.c extra.c
SRC = $(addprefix $(SRC_PATH), $(SRCS_FILES))

OBJECTS_PATH = ./objs/
OBJECTS_FILES = $(subst .c,.o,$(SRCS_FILES))
OBJECTS = $(addprefix $(OBJECTS_PATH), $(OBJECTS_FILES))

LIB_SRCS_PATH = ./libft/
LIB_SRC_FILES = ft_putchar.c ft_putendl.c ft_strncpy.c ft_isalnum.c ft_atoi.c ft_putstr.c \
				ft_isdigit.c ft_isalpha.c ft_printbit.c ft_strlen.c ft_isdigit.c \
				ft_putnbr_base.c ft_itoa_base.c ft_memset.c ft_capitalize.c ncount.c ft_strdel.c\
				ft_bzero.c ft_strdup.c ft_uitoa_base.c ft_strjoin.c ft_strcpy.c ft_strsub.c \
				ft_strnew.c ft_memcpy.c ncount_base.c ft_abs.c ft_itoa.c ft_memalloc.c ft_strcmp.c \
				ft_lstputstr.c
LIB_SRC = $(addprefix $(LIB_SRCS_PATH), $(LIB_SRC_FILES))

LIB_OBJECTS_PATH =./objs/
LIB_OBJECTS_FILES = $(subst .c,.o,$(LIB_SRC_FILES))
LIB_OBJECTS = $(addprefix $(LIB_OBJECTS_PATH), $(LIB_OBJECTS_FILES))

COMPILE = gcc -Wall -Werror -Wextra

INCLUDES = -I ./includes/
HEADER_PATH = ./includes/
HEADER_FILES = ft_printf.h
HEADERS = $(addprefix $(HEADER_PATH), $(HEADER_FILES))

COLOR_RESET = \033[0m
COLOR_PENDING = \033[0;33m
COLOR_SUCCESS = \033[0;32m
COLOR_DEFAULT = \033[1;34m

all: $(NAME)

$(NAME): $(OBJECTS) $(LIB_OBJECTS) $(HEADERS)
		@echo "$(NAME)	[$(COLOR_PENDING)Complining...$(COLOR_RESET)]"
		@ar rc $(NAME) $(OBJECTS) $(LIB_OBJECTS)
		@ranlib $(NAME)
		@echo "$(NAME)	[$(COLOR_SUCCESS)OK$(COLOR_RESET)]"
		@echo "$(NAME)	[$(COLOR_SUCCESS)FINISHED$(COLOR_RESET)]"
		@make -C libft/

$(OBJECTS_PATH)%.o: $(SRC_PATH)%.c
		@mkdir $(OBJECTS_PATH) 2>/dev/null || echo "" > /dev/null
		@$(COMPILE) $(INCLUDES) -c $< -o $@

$(LIB_OBJECTS_PATH)%.o: $(LIB_SRCS_PATH)%.c
		@mkdir $(LIB_OBJECTS_PATH) 2>/dev/null || echo "" > /dev/null
		@$(COMPILE) $(INCLUDES) -c $< -o $@

clean:
		@rm -fv $(OBJECTS) > /dev/null
		@rm -rf $(OBJECTS_PATH) > /dev/null
		@rm -f libft/*.o

fclean: clean
		@rm -fv $(NAME) > /dev/null
		@rm -fv libft/libft.a

re: fclean all

.PHONY = all clean fclean re
