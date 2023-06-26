NAME=fract_ol
NAMEB=bonus
CC = cc
SRC = utils.c utils_mlx.c fract_ol.c mandelbrot.c julia.c keyhook.c mousehook.c color.c
SRCB = fract_ol_bonus.c utils.c utils_mlx.c mandelbrot.c julia.c keyhook.c mousehook.c color.c
OBJ=$(SRC:.c=.o)
OBJB=$(SRCB:.c=.o)
CFLAGS = -Wall -Werror -Wextra -Imlx
LINKER_FLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME) $(LINKER_FLAGS)

$(NAMEB) : $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) -o $(NAMEB) $(LINKER_FLAGS)

%.o: %.c
	$(CC) -Wall -Wextra -Werror $(CFLAGS) -c $< -o $@

bonus: $(NAMEB)

clean:
	@rm -rf $(OBJ) $(OBJB)

fclean: clean
	@rm -rf $(NAME) $(NAMEB)

re: fclean all

.PHONY : all clean fclean re
