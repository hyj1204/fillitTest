NAME = fillit

SRC = main.c \
	  ft_create.c \
	  ft_read_piece.c \
	  ft_fill.c \
	  ft_append_fnode.c \
	  ft_validation.c \
	  ft_print.c \
	  ft_free.c \
	  ft_error.c

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
