SRCS 		=	settings/fdf.c \
				settings/read_map.c \
				settings/load_map.c \
				settings/create_map.c \
				settings/free_table.c \
				settings/load_mlx.c \
				settings/map_get_data.c \
				settings/map_validate.c \
				settings/message.c \
				color/color_functions.c \
				events/load_hooks.c \
				events/handle_input.c \
				events/exit_fdf.c \
				render/pixel_put.c \
				render/background.c \
				render/render.c \
				render/bresenham_line.c \
				render/draw_map.c \
				transform/map_iterator.c \
				transform/transformations.c \
				transform/center_origin.c \
				transform/isometric_view.c

OBJS		=	${SRCS:%.c=$(OBJS_DIR)%.o}
OBJS_DIR	=	objects/
HEADER 		=	fdf.h
NAME		=	fdf
CC			=	cc
CFLAGS		=	-g -Wall -Wextra -Werror
LIBS		=	libft/libft.a -lmlx -lX11 -lXext -lm
RM			=	rm -rf

ifeq ($(shell uname), Darwin) # MacOS
	LIBS	:=	libft/libft.a -lmlx -framework OpenGL -framework AppKit
endif

$(OBJS_DIR)%.o:	%.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -c $< -o $@ -I includes

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
