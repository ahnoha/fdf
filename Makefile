NAME = fdf
CC = gcc -Wall -Wextra -Werror -Imlx
HEADERS = fdf.h
SRC = 	fdf.c\
		main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f pipex

re: fclean all
