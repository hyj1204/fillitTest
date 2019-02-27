# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 11:48:07 by yijhuang          #+#    #+#              #
#    Updated: 2019/02/24 23:49:08 by yijhuang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c \
	  f_append_fnode.c \
	  f_fill.c	\
	  f_read_piece.c	\
	  f_validation.c	\
	  ft_create.c	\
	  ft_free.c \
		ft_print.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)   #只有在.c文件有变换（有修改）的时候才执行下面的语句
	# gcc -g $(SRC) -o $(NAME)
	gcc -c $(FLAGS) $(SRC)  #编译所有的.c文件，变为.o文件(object)
	gcc $(OBJ) -o $(NAME)  #编译所有的.o文件，生成名字为fillit的可执行文件

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
