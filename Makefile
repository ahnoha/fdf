NAME = fdf
CC = gcc -Wall -Wextra -Werror -Imlx
HEADERS = fdf.h ./gnl/get_next_line.h
SRC = 	fdf.c \
		./ft_split/ft_split.c \
		./ft_split/ft_split_utils.c \
		./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c \
		ft_mlx_pixel_put.c \
		ft_init.c \
		ft_color.c \
		main.c

INCLUDES_PATH = -I ./ -I ./gnl/
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(INCLUDES_PATH)

%.o: %.c $(HEADERS)
	$(CC) $(INCLUDES_PATH) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
