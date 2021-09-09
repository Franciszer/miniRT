/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:41:14 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:40:51 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_inter		**get_inter_screen(int w, int h)
{
	t_inter	**inter;
	int		i;

	if (!(inter = (t_inter**)malloc(sizeof(t_inter*) * h)))
		return ((t_inter**)0);
	i = 0;
	while (i < h)
	{
		if (!(inter[i] = (t_inter*)malloc(sizeof(t_inter) * w)))
			return (free_inter(inter, i));
		i++;
	}
	return (inter);
}

t_inter		**inter_rt(t_obj *obj, t_cam *cam, t_canvas canvas)
{
	t_inter	**inter;
	int		i;
	int		j;

	if (!(inter = get_inter_screen(obj->res->x, obj->res->y)))
		return (0);
	i = 0;
	while (i < obj->res->y)
	{
		j = -1;
		while (++j < obj->res->x)
		{
			inter[i][j] = get_inter(cam->o, cam->o, 0, NULL);
			inter[i][j] = sphere_iter(obj->sphere_list, cam->o,\
							canvas.screen[i][j], inter[i][j]);
			inter[i][j] = plane_iter(obj->plane_list, cam->o,\
							canvas.screen[i][j], inter[i][j]);
			inter[i][j] = tri_iter(obj->tri_list, cam->o,\
							canvas.screen[i][j], inter[i][j]);
			inter[i][j] = cyl_iter(obj->cyl_list, cam->o,\
							canvas.screen[i][j], inter[i][j]);
		}
		i++;
	}
	return (inter);
}

int			is_clearpath(t_obj *obj, t_vec3 o, t_light *light)
{
	t_inter	inter;
	double	d_to_light;
	t_vec3	d;

	d_to_light = norm2(op_vec3(light->o, '-', o));
	d = normalize(op_vec3(light->o, '-', o));
	inter = get_inter(o, o, 0, NULL);
	inter = sphere_iter(obj->sphere_list, o, d, inter);
	inter = plane_iter(obj->plane_list, o, d, inter);
	inter = tri_iter(obj->tri_list, o, d, inter);
	inter = cyl_iter(obj->cyl_list, o, d, inter);
	if (inter.d_to_o == INIT_D || inter.d_to_o + EPS > d_to_light)
		return (1);
	else
		return (0);
}

t_inter		**get_colors_rt(t_obj *obj)
{
	t_cam		*cam;
	t_canvas	canvas;
	t_inter		**inter;

	cam = obj->cam_list->content;
	canvas.o = cam->o;
	if (!(canvas.screen = (t_vec3**)get_canvas_rt(cam, obj)))
		return ((t_inter**)0);
	if (!(inter = inter_rt(obj, cam, canvas)))
		return ((t_inter**)0);
	get_canvas_light(obj, obj->res->x, obj->res->y, inter);
	return (inter);
}

int			get_inters_rt(t_obj *obj)
{
	t_list		*nav;
	t_cam		*cam;
	t_canvas	canvas;
	t_inter		**inter;
	t_list		*new_inter;

	nav = obj->cam_list;
	while (nav)
	{
		cam = (t_cam*)nav->content;
		canvas.o = cam->o;
		if (!(canvas.screen = (t_vec3**)get_canvas_rt(cam, obj)))
			return (0);
		if (!(inter = inter_rt(obj, cam, canvas)))
			return (0);
		if (!(new_inter = ft_lstnew(inter)))
			return (0);
		get_canvas_light(obj, obj->res->x, obj->res->y, inter);
		free_canvas(canvas.screen, obj->res->y);
		ft_lstadd_front(&obj->inter_list, new_inter);
		nav = nav->next;
	}
	return (1);
}
