NAME = fillit

SRC = main.c \
	  f_create.c \
	  f_read_piece.c \
	  f_fill.c \
	  f_append_fnode.c \
	  f_validation.c \
	  f_print.c \
	  f_free.c \
	  f_error.c

OBJ = $(SRC:.c=.o)

INC = fillit.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):  $(SRC)
	gcc -c $(FLAGS) $(SRC)
	gcc $(OBJ) -o $(NAME)
#	$(CC) -g -o $(NAME) $(MAIN) $(OBJ) -L ./libft/ -lft

clean:
#	make -C libft clean
	rm -f $(OBJ)

fclean: clean
#	make -C libft fclean
	rm -f $(NAME)

re: fclean all