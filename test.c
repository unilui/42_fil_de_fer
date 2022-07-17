#include "fdf.h"
#include <stdio.h>

int render_rect(t_screen *screen, t_rect rect)
{
	int	x;
	int	y;

	y = rect.y;
	while (y < (rect.y + rect.height))
	{
		x = rect.x;
		while (x < (rect.x + rect.width))
			mlx_pixel_put(screen->mlx, screen->window, x++, y, rect.color);
		y++;
	}
	return (0);
}

int	render(t_screen *screen)
{
	render_rect(screen, (t_rect){
		(WINDOW_WIDTH / 2 - 50), (WINDOW_HEIGHT / 2 - 50),
		100, 100, rgb_encode(0, 255, 0)
	});
	return (0);
}

int	handle_input(int keysym, t_screen *data)
{
	if (keysym == 53)
	{
		mlx_destroy_window(data->mlx, data->window);
		exit(0);
	}
	return (0);
}

int	sair(t_screen *data)
{
	exit(0);
}

int main(void)
{
	t_screen	screen;	
	
	screen.mlx = mlx_init();
	screen.window = mlx_new_window(screen.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello, screen!");
	
	render(&screen);
	mlx_key_hook(screen.window, &handle_input, &screen);
	mlx_hook(screen.window, 17, 0, &sair, &screen);
	mlx_loop(screen.mlx);
	//mlx_destroy_display(screen.mlx); -> only linux
	free(screen.mlx);
	return (0);
}
