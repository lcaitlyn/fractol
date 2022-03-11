NAME		=	fractol

HEADER		=	fractol.h

SRCS		= 	fractol.c

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
