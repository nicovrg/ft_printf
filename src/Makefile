# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/11 22:26:09 by nivergne          #+#    #+#              #
#    Updated: 2019/01/14 15:19:30 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	main.c \
		test.c \
		else.c \
		itoa_base.c \
		print_csp.c \
		print_ui.c \
		print_base.c \
		padding.c \
		witdth.c \
		parse.c \
		ft_printf.c \
		#padding.c \
		mem.c \

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wextra -Werror -Wall

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	@cp libft/libft.a ./$(NAME)
	$(CC) $(CFLAGS) -c $(SRCS) -I../
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)
	make clean -C libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all clean fcean re

