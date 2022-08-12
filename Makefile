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
				events/handle_mouse.c \
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
CFLAGS		=	-Wall -Wextra -Werror
LIBS		=	libft/libft.a -lmlx -lX11 -lXext -lm
RM			=	rm -rf

$(OBJS_DIR)%.o:	%.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -c $< -o $@ -I includes

all:		$(NAME)

$(NAME):	$(OBJS) libft
			@$(CC) $(OBJS) -o $(NAME) $(LIBS)

libft:
			@make -C libft --no-print-directory

libft_fclean:
			@make fclean -C libft --no-print-directory

run:		re
			./$(NAME) test_maps/42.fdf

clean:		libft_fclean
			@$(RM) $(OBJS_DIR)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re run libft
