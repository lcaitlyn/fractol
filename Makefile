NAME		=	fractol

HEADER		=	fractol.h

SRCS		= 	fractol.c key_commands.c ./formulas/mandelbrot.c\
				get_color.c ft_utils.c ft_strnstr.c\
				draw.c ft_init.c mouse_commands.c\
				./formulas/julia.c ./formulas/burning_ship.c
				

OBJ			=	$(SRCS:%.c=%.o)






FLAGS		=









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
