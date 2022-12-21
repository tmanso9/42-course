NAME = fractol
CC = cc
#CFLAGS = -Wall -Wextra -Werror
CFLAGS += -fsanitize=address -g3
SRC = new_main.c \
	draw.c \
	shapes.c \
	render.c \
	mandelbrot.c
OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all