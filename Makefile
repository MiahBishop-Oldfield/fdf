NAME = fdf
 
SRCS = sources/*.c

MLX = minilibx
LIBFT = libft
INC = includes

LIBS = -L$(MLX) -lmlx -L$(LIBFT) -lft
HEADERS = -I$(INC) -I$(MLX) -I$(LIBFT)
FLAGS = $(LIBS) $(HEADERS) -framework OpenGL -framework AppKit

all:
	@make -s -C $(MLX)
	@make -s -C $(LIBFT)
	@gcc $(SRCS) $(FLAGS) -o $(NAME)
	@echo Compiling libraries...
	@echo Wireframe ready to go.

clean:
	@make clean -s -C $(MLX)
	@make fclean -s -C $(LIBFT)
	@rm -f $(NAME)
	@rm -rf $(OBJS)
	@rm -rf sources/*.o
	@rm -rf libft/*.o
	@echo Cleaning up...
	@echo Clean complete.

fclean: clean

re: clean all