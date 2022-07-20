#include "fdf.h"
#include <stdio.h>

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*addr;
	int		*pixel;

	addr = img->addr + (y * img->line_len + x * (img->bpp / 8));
	pixel = (int *)addr;
	*pixel = color;
}

int render_rect(t_img *img, t_rect rect)
{
	int	x;
	int	y;

	y = rect.y;
	while (y < (rect.y + rect.height))
	{
		x = rect.x;
		while (x < (rect.x + rect.width))
			img_pixel_put(img, x++, y, rect.color);
		y++;
	}
	return (0);
}

int render_background(t_img *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
			img_pixel_put(img, x++, y, color);
		y++;
	}
	return (0);
}

int	render(t_screen *screen)
{
	render_background(&screen->img, rgb_encode(255, 255, 255));
	render_rect(&screen->img, (t_rect){
		(WINDOW_WIDTH / 2 - 50), (WINDOW_HEIGHT / 2 - 50),
		100, 100, rgb_encode(0, 255, 0)
	});
	mlx_put_image_to_window(screen->mlx, screen->window, screen->img.mlx_img, 0, 0);
	return (0);
}

int	handle_input(int keysym, t_screen *screen)
{
	if (keysym == 53)
	{
		mlx_destroy_window(screen->mlx, screen->window);
		exit(0);
	}
	return (0);
}

int	sair(t_screen *screen)
{
	exit(0);
}

int main(void)
{
	t_screen	screen;	
	
	screen.mlx = mlx_init();
	screen.window = mlx_new_window(screen.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello, screen!");
	screen.img.mlx_img = mlx_new_image(screen.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	screen.img.addr = mlx_get_data_addr(
		screen.img.mlx_img,
		&screen.img.bpp,
		&screen.img.line_len,
		&screen.img.endian);

	mlx_loop_hook(screen.mlx, &render, &screen);
	mlx_key_hook(screen.window, &handle_input, &screen);
	mlx_hook(screen.window, 17, 0, &sair, &screen);
	mlx_loop(screen.mlx);
	//mlx_destroy_display(screen.mlx); -> only linux
	free(screen.mlx);
	return (0);
}
