# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/11 22:26:09 by nivergne          #+#    #+#              #
#    Updated: 2019/01/18 00:55:29 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	src/mem.c \
		src/test.c \
		src/else.c \
		src/print_%.c \
		src/print_c.c \
		src/print_s.c \
		src/print_p.c \
		src/print_i.c \
		src/print_o.c \
		src/print_u.c \
		src/print_x.c \
		src/width_csp.c \
		src/width_dioux.c \
		src/itoa_base.c \
		src/parse.c \
		src/ft_printf.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wextra -Werror -Wall -I ../include/

#CFLAGS = -Wextra -Werror -Wall -I./include/

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

