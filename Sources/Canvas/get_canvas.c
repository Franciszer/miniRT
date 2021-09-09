/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_canvas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 23:58:46 by franciszer        #+#    #+#             */
/*   Updated: 2020/02/22 18:40:16 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec3	**canvas_alloc(int w, int h)
{
	t_vec3	**canvas;
	int		i;

	i = 0;
	if (!(canvas = (t_vec3**)malloc(sizeof(t_vec3*) * h)))
		return ((t_vec3**)0);
	while (i < h)
	{
		if (!(canvas[i] = (t_vec3*)malloc(sizeof(t_vec3) * w)))
			return (free_canvas(canvas, i));
		i++;
	}
	return (canvas);
}

t_vec3			**free_canvas(t_vec3 **canvas, int h_max)
{
	int	i;

	i = 0;
	while (i < h_max)
	{
		free(canvas[i]);
		i++;
	}
	free(canvas);
	return ((t_vec3**)0);
}

t_vec3			**get_canvas_rt(t_cam *cam, t_obj *obj)
{
	int			i;
	int			j;
	t_vec3		**canvas;
	double		fov_rad;

	if (!(canvas = canvas_alloc((int)obj->res->x, (int)obj->res->y)))
		return ((t_vec3**)0);
	fov_rad = cam->fov * M_PI / 180;
	i = 0;
	while (i < obj->res->y)
	{
		j = 0;
		while (j < obj->res->x)
		{
			canvas[i][j] = get_vec3(j - (double)obj->res->x / 2,\
			i - (double)obj->res->y / 2,\
			(double)obj->res->x / (2 * tan(fov_rad / 2)));
			canvas[i][j] = normalize(\
			rot_vec3(canvas[i][j], cam->d, get_vec3(0, 0, 1)));
			j++;
		}
		i++;
	}
	return (canvas);
}
