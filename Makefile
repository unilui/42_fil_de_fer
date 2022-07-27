SRCS 		=	fdf.c	color_functions.c load_map.c \
				free_table.c \
				load_mlx.c \
				event_functions/load_hooks.c \
				event_functions/handle_input.c \
				event_functions/exit_fdf.c \
				render_functions/render_grid.c \
				render_functions/img_pixel_put.c \
				render_functions/render_background.c \
				render_functions/render.c

OBJS		=	${SRCS:%.c=$(OBJS_DIR)%.o}
OBJS_DIR	=	objects/
HEADER 		=	fdf.h
NAME		=	fdf
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
LIBS		=	libft/libft.a -lmlx -lX11 -lXext -lm
RM			=	rm -rf

ifeq ($(shell uname), Darwin) # MacOS
	LIBS	:=	libft/libft.a -lmlx -framework OpenGL -framework AppKit
endif

$(OBJS_DIR)%.o:	%.c
			@mkdir -p $(dir $@)
			@$(CC) -c $< -o $@

$(NAME):	$(OBJS)
			@$(CC) $(OBJS) -o $(NAME) $(LIBS)

all:		$(NAME)

run:		re
			./$(NAME) test_maps/42.fdf

clean:
			@$(RM) $(OBJS_DIR)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re run