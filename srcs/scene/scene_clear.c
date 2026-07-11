#include "scene.h"
#include <stdlib.h>

void	scene_clear(t_scene *scene)
{
	t_object	*cur;
	t_object	*next;

	if (!scene)
		return ;
	cur = scene->objects;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	scene->objects = NULL;
}

void	scene_add_object(t_scene *scene, t_object *obj)
{
	t_object	*tail;

	if (!scene->objects)
	{
		scene->objects = obj;
		return ;
	}
	tail = scene->objects;
	while (tail->next)
		tail = tail->next;
	tail->next = obj;
	obj->next = NULL;
}