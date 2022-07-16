#include <stdlib.h>
#include <mlx.h>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000

#define BLUE 0
#define GREEN 1
#define RED 2

typedef union u_color
{
	int	color;
	char rgb[4];
}	t_color;

typedef struct s_screen
{
	void	*mlx;
	void	*window;
}	t_screen;

int main(void)
{
	t_screen	screen;	
	t_color		line;
	int i;

	i = 0;
	line.rgb[RED] = 0;
	line.rgb[GREEN] = 0;
	line.rgb[BLUE] = 255;

	screen.mlx = mlx_init();
	screen.window = mlx_new_window(screen.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello, screen!");
	while (i++ <= WINDOW_WIDTH)
	{
		mlx_pixel_put(screen.mlx, screen.window, i, WINDOW_HEIGHT / 2, line.color);
	}
	while (1)
		;
	mlx_destroy_window(screen.mlx, screen.window);
	mlx_destroy_display(screen.mlx);
	free(screen.mlx);
	
}

// cc test.c -lX11 -lXext -lmlx
