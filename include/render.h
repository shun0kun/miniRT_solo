#ifndef RENDER_H
# define RENDER_H

# include "scene.h"
# include "image.h"
# include "ray.h"

void	render(const t_scene *scene, t_image *image);
t_ray	camera_ray(const t_camera *camera, const t_image *image, int x, int y);
t_color	trace_ray(const t_scene *scene, t_ray ray);

#endif
