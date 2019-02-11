 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/11 22:26:09 by nivergne          #+#    #+#              #
#    Updated: 2019/01/26 22:52:02 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norme

CC = gcc

FLAGS = -Wall -Wextra -Werror -Ofast

NAME = libftprintf.a

INCLUDE = -I./include/

SRC_PATH = ./src
LIB_PATH = ./libft
INC_PATH = ./include/
OBJ_PATH = ./obj
OBJLIB_PATH = ./obj

SRC_NAME =	./else.c \
			./print_per.c \
			./print_b.c \
			./print_c.c \
			./print_s.c \
			./print_p.c \
			./print_i.c \
			./print_o.c \
			./print_u.c \
			./print_x.c \
			./print_f.c \
			./print_ff.c \
			./width_csp.c \
			./width_dioux.c \
			./convert_base.c \
			./parse.c \
			./ft_printf.c

LIB_NAME = 	./ft_bzero.c\
			./ft_memset.c\
			./ft_memalloc.c\
			./ft_putchar.c\
			./ft_putstr.c\
			./ft_putnbr.c\
			./ft_strlen.c\
			./ft_strjoin.c\
			./ft_strcpy.c\

INC_NAME = ft_printf.h
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJLIB_NAME = $(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJLIB = $(addprefix $(OBJLIB_PATH)/,$(OBJLIB_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB)
	@ar rc $(NAME) $(OBJ) $(OBJLIB)
	@ranlib $(NAME)
	@echo "          __, ___      __, __, _ _, _ ___ __,"
	@echo "          |_   |       |_) |_) | |\ |  |  |_ "
	@echo "          |    |       |   | \ | | \|  |  |  "
	@echo "          ~    ~  ~~~~ ~   ~ ~ ~ ~  ~  ~  ~  "
	@echo ""
	@echo "             (         ) "
	@echo "	              )        ("
	@echo "               ___)...----)----....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@echo "\033[1;34mft_printf\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) $(INCLUDE) -o $@ -c $<

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
	@mkdir $(OBJLIB_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) $(INCLUDE) -o $@ -c $<

clean:
	@rm -rf $(OBJ) $(OBJLIB)
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -rf ./obj $(NAME)
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all
