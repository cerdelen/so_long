SRCS = main.c specific_error_messages.c check_maps.c handle_argument.c create_map.c so_long_game.c move_functions.c images_and_render.c

NAME = so_long

MLX = libmlx.a -framework OpenGL -framework AppKit

OBJS =	$(SRCS:.c=.o)

LIB =	./Libft/libft.a

GNL =	./get_next_line/get_next_line.a

all: $(LIB) $(GNL) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME) $(LIB) $(GNL)

$(LIB):
	$(MAKE) bonus -C Libft

$(GNL):
	$(MAKE) -C get_next_line

clean:
	$(MAKE) fclean -C Libft
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) 

re: fclean all