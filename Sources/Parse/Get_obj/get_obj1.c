/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:08:29 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:41:40 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		get_plane(double *vals, t_obj *obj)
{
	t_plane	*plane;
	t_list	*new;

	if (!(plane = (t_plane*)malloc(sizeof(t_plane))))
		return (0);
	plane->o.x = vals[0];
	plane->o.y = vals[1];
	plane->o.z = vals[2];
	plane->d.x = vals[3];
	plane->d.y = vals[4];
	plane->d.z = vals[5];
	plane->rgb[0] = (unsigned char)vals[6];
	plane->rgb[1] = (unsigned char)vals[7];
	plane->rgb[2] = (unsigned char)vals[8];
	plane->d = normalize(plane->d);
	if (!(new = ft_lstnew((void *)plane)))
		return (0);
	ft_lstadd_front(&obj->plane_list, new);
	return (1);
}

int		get_cyl(double *vals, t_obj *obj)
{
	t_cyl	*cyl;
	t_list	*new;

	if (!(cyl = (t_cyl*)malloc(sizeof(t_cyl))))
		return (0);
	cyl->o.x = vals[0];
	cyl->o.y = vals[1];
	cyl->o.z = vals[2];
	cyl->d.x = vals[3];
	cyl->d.y = vals[4];
	cyl->d.z = vals[5];
	cyl->r = vals[6] / 2;
	cyl->h = vals[7];
	cyl->rgb[0] = (unsigned char)vals[8];
	cyl->rgb[1] = (unsigned char)vals[9];
	cyl->rgb[2] = (unsigned char)vals[10];
	if (!(new = ft_lstnew((void *)cyl)))
		return (0);
	ft_lstadd_front(&obj->cyl_list, new);
	return (1);
}

int		get_triangle(double *vals, t_obj *obj)
{
	t_tri	*tri;
	t_list	*new;

	if (!(tri = (t_tri*)malloc(sizeof(t_tri))))
		return (0);
	tri->a.x = vals[0];
	tri->a.y = vals[1];
	tri->a.z = vals[2];
	tri->b.x = vals[3];
	tri->b.y = vals[4];
	tri->b.z = vals[5];
	tri->c.x = vals[6];
	tri->c.y = vals[7];
	tri->c.z = vals[8];
	tri->rgb[0] = (unsigned char)vals[9];
	tri->rgb[1] = (unsigned char)vals[10];
	tri->rgb[2] = (unsigned char)vals[11];
	if (!(new = ft_lstnew((void *)tri)))
		return (0);
	ft_lstadd_front(&obj->tri_list, new);
	return (1);
}
