NAME		=	fractol

HEADER		=	fractol.h

SRCS		= 	./source/fractol.c ./source/key_commands.c\
				./source/get_color.c ./source/ft_utils.c ./source/ft_strnstr.c\
				./source/draw.c ./source/ft_init.c ./source/mouse_commands.c\
				./formulas/julia.c ./formulas/burning_ship.c ./formulas/mandelbrot.c\
				

OBJ			=	$(SRCS:%.c=%.o)

FLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	-I /usr/local/include

MLX			=	-L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

.PHONY		:	all clean fclean re

all			:	$(NAME)

%.o			:	%.c $(HEADER)
					@gcc $(FLAGS) -Imlx -c $< -o $@


$(NAME)		:	$(OBJ)
					@gcc $(FLAGS) $(INCLUDE) $(MLX) -o $(NAME) $(OBJ)

clean		:
					@rm -f $(OBJ)

fclean		:	clean
					@rm -f $(NAME)

re			:	fclean all
