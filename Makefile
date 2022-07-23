SRCS 		=	fdf.c	color_functions.c load_map.c \
				utils/ft_chrpst.c \
				utils/ft_strdup.c \
				utils/ft_strjoin.c \
				utils/ft_strlen.c \
				utils/ft_substr.c \
				utils/get_next_line.c \
				utils/ft_split.c \
				utils/ft_strtrim.c \
				utils/ft_strrchr.c \
				utils/ft_atoi.c \
				free_table.c \
				load_mlx.c \
				event_functions/load_hooks.c \
				event_functions/handle_input.c \
				event_functions/exit_fdf.c \
				render_functions/render_grid.c \
				render_functions/img_pixel_put.c \
				render_functions/render_background.c \
				render_functions/render_rect.c \
				render_functions/render.c

OBJS		=	${SRCS:%.c=$(OBJS_DIR)%.o}
OBJS_DIR	=	objects/
HEADER 		=	fdf.h utils/get_next_line.h
NAME		=	fdf
CC			=	cc
CFLAGS		=	-g
RM			=	rm -rf

ifeq ($(shell uname), Darwin) # MacOS
	CFLAGS	:= -lmlx -framework OpenGL -framework AppKit
endif

$(OBJS_DIR)%.o:	%.c
			@mkdir -p $(dir $@)
			@$(CC) -c $< -o $@

$(NAME):	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

run:		re
			./${NAME} test_maps/42.fdf

clean:
			${RM} ${OBJS}; ${RM} ${OBJS_DIR}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re run