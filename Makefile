NAME = fractol

CC = cc
FLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm
RM = rm -f


SOURCES = fractol.c \
		ft_strncmp.c \
		ft_strdup.c \
		draw.c\
		init.c \
		julia.c \
		mandelbrot.c \
		burning_ship.c \
		exit.c \
		utils.c \

OBJECTS = $(SOURCES:.c=.o)

HEADER = fractol.h

%.o: %.c

	$(CC) $(FLAGS) -I./minilibx-linux -c $< -o $@

$(NAME): $(OBJECTS)
	make -C ./minilibx-linux
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(MLX_FLAGS) 

all: $(NAME)

re: clean fclean all

clean:
	$(RM) $(OBJECTS)
	make -C ./minilibx-linux clean

fclean: clean
	$(RM) $(NAME)


.PHONY: all clean fclean re