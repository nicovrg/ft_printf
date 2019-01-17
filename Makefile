# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/11 22:26:09 by nivergne          #+#    #+#              #
#    Updated: 2019/01/17 02:20:28 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	src/test.c \
		src/else.c \
		src/mem.c \
		src/parse.c \
		src/itoa_base.c \
		src/width_csp.c \
		src/width_ui.c \
		src/print_csp.c \
		src/print_ui.c \
		src/print_base.c \
		src/ft_printf.c \

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wextra -Werror -Wall -I./include/

all: $(NAME)

$(NAME): $(OBJS)
	#make -C libft/
	#@cp libft/libft.a ./$(NAME)
	@mkdir objs
	$(CC) $(CFLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@mv ./src/*.o ./objs/
	@rm -rf ./*.o

clean:
	@rm -rf $(OBJS)
	@rm -rf ./objs/
	#make clean -C libft/

fclean: clean
	@rm -rf $(NAME)
	#make fclean -C libft/

re: fclean all

.PHONY: all clean fcean re

