/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 12:35:16 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:41:34 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		get_res(double *vals, t_obj *obj)
{
	if (!obj->res)
	{
		if (!(obj->res = (t_res*)malloc(sizeof(t_res))))
			return (0);
		obj->res->x = (int)vals[0];
		obj->res->y = (int)vals[1];
		return (1);
	}
	return ((int)print_error(ERR_RES_MUCH));
}

int		get_cam(double *vals, t_obj *obj)
{
	t_list	*new;
	t_cam	*cam;

	if (!(cam = (t_cam *)malloc(sizeof(t_cam))))
		return (0);
	cam->o.x = vals[0];
	cam->o.y = vals[1];
	cam->o.z = vals[2];
	cam->d.x = vals[3];
	cam->d.y = vals[4];
	cam->d.z = vals[5];
	cam->fov = vals[6];
	if (!(new = ft_lstnew((void *)cam)))
		return (0);
	ft_lstadd_front(&obj->cam_list, new);
	return (1);
}

int		get_alight(double *vals, t_obj *obj)
{
	t_list		*new;
	t_alight	*alight;

	if (!(alight = (t_alight*)malloc(sizeof(t_alight))))
		return (0);
	alight->brightness = vals[0];
	alight->rgb[0] = (unsigned char)vals[1];
	alight->rgb[1] = (unsigned char)vals[2];
	alight->rgb[2] = (unsigned char)vals[3];
	if (!(new = ft_lstnew((void *)alight)))
		return (0);
	ft_lstadd_front(&obj->alight_list, new);
	return (1);
}

int		get_light(double *vals, t_obj *obj)
{
	t_list		*new;
	t_light		*light;

	if (!(light = (t_light*)malloc(sizeof(t_light))))
		return (0);
	light->o.x = vals[0];
	light->o.y = vals[1];
	light->o.z = vals[2];
	light->brightness = vals[3];
	light->rgb[0] = (unsigned char)vals[4];
	light->rgb[1] = (unsigned char)vals[5];
	light->rgb[2] = (unsigned char)vals[6];
	if (!(new = ft_lstnew((void *)light)))
		return (0);
	ft_lstadd_front(&obj->light_list, new);
	return (1);
}

int		get_sphere(double *vals, t_obj *obj)
{
	t_sphere	*sphere;
	t_list		*new;

	if (!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		return (0);
	sphere->c.x = vals[0];
	sphere->c.y = vals[1];
	sphere->c.z = vals[2];
	sphere->diameter = vals[3];
	sphere->rgb[0] = (unsigned char)vals[4];
	sphere->rgb[1] = (unsigned char)vals[5];
	sphere->rgb[2] = (unsigned char)vals[6];
	if (!(new = ft_lstnew((void *)sphere)))
		return (0);
	ft_lstadd_front(&obj->sphere_list, new);
	return (1);
}
