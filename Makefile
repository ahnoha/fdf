NAME = fdf
CC = gcc -Wall -Wextra -Werror -Imlx
HEADERS = fdf.h structures.h ./gnl/get_next_line.h ./ft_split/split.h ./list/list.h ./parse/parse.h ./draw/draw.h

SRC = 	./ft_split/ft_split.c \
		./ft_split/ft_split_utils.c \
		./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c \
		./list/add_back.c \
		./list/elem_new.c \
		./list/list_new.c \
		./list/list_del.c \
		ft_mlx_pixel_put.c \
		ft_init.c \
		iso.c \
		./parse/parse_line.c \
		./parse/parse_lines.c \
		./parse/ft_free.c \
		./parse/list_to_array.c \
		key_hook.c \
		./parse/to_decimal.c \
		./parse/del_point.c \
		./parse/free_points.c \
		./parse/ft_atoi.c \
		./draw/draw_line.c \
		./draw/draw_lines.c \
		./draw/ft_draw.c \
		main.c

INCLUDES_PATH = -I ./  -I./ft_split -I./gnl/ -I./list/ -I./parse/ -I./draw/
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
