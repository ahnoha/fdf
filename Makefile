NAME = fdf
CC = gcc -Wall -Wextra -Werror -Imlx
HEADERS = fdf.h
SRC = 	fdf.c \
		ft_mlx_pixel_put.c \
		ft_init.c \
		ft_color.c \
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

re: fclean all
