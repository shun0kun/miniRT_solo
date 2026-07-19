#include "minirt.h"
#include "render.h"
#include "mlx.h"

bool	minirt_init(t_minirt *rt, const char *filepath)
{
	*rt = (t_minirt){0};
	if (!scene_load(filepath, &rt->scene))
		return (false);
	rt->mlx = mlx_init();
	rt->window = mlx_new_window(rt->mlx, 1920, 1080, "miniRT");
	rt->image.width = 1920;
	rt->image.height = 1080;
	rt->image.ptr = mlx_new_image(rt->mlx, rt->image.width, rt->image.height);
	rt->image.pixels = mlx_get_data_addr(rt->image.ptr, &rt->image.bits_per_pixel, &rt->image.line_length, &rt->image.endian);
	return (true);
}

// mlx_destroy_displayはlinuxの時だけ。
// NULLチェックのどもやる。
void	minirt_destroy(t_minirt *rt)
{
	scene_clear(&rt->scene);
	mlx_destroy_image(rt->window, rt->image.ptr);
	mlx_destroy_window(rt->mlx, rt->window);
	// mlx_destroy_display(app->mlx);
}

void	minirt_run(t_minirt *rt)
{
	render(&rt->scene, &rt->image);
	mlx_put_image_to_window(rt->mlx, rt->window, rt->image.ptr, 0, 0);
	// mlx_hook();
	mlx_loop(rt->mlx);
}
