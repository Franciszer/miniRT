/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inter_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:17:38 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:40:46 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_inter_sphere(t_inter *inter, void *obj_inter, t_vec3 o)
{
	t_sphere	*sphere;
	int			i;

	sphere = (t_sphere*)obj_inter;
	inter->normal = normalize(op_vec3(inter->point, '-', sphere->c));
	if (norm(op_vec3(sphere->c, '-', o)) < sphere->diameter / 2)
		inter->normal = opf_vec3(inter->normal, '*', -1);
	i = 0;
	while (i < 3)
	{
		inter->rgb[i] = sphere->rgb[i];
		i++;
	}
}

void	get_inter_plane(t_inter *inter, void *obj_inter, t_vec3 o)
{
	t_plane	*plane;
	int		i;

	plane = (t_plane*)obj_inter;
	inter->normal = get_vec3(plane->d.x, plane->d.y, plane->d.z);
	if (norm(op_vec3(op_vec3(inter->point, '+', inter->normal), '-', o)) >\
	norm(op_vec3(op_vec3(inter->point, '-', inter->normal), '-', o)))
		inter->normal = opf_vec3(inter->normal, '*', -1);
	i = 0;
	while (i < 3)
	{
		inter->rgb[i] = plane->rgb[i];
		i++;
	}
}

void	get_inter_tri(t_inter *inter, void *obj_inter, t_vec3 o)
{
	t_tri	*tri;
	int		i;
	t_vec3	ab;
	t_vec3	ac;

	tri = (t_tri*)obj_inter;
	ab = op_vec3(tri->b, '-', tri->a);
	ac = op_vec3(tri->c, '-', tri->a);
	inter->normal = normalize(cross_vec3(ab, ac));
	if (norm(op_vec3(op_vec3(inter->point, '+', inter->normal), '-', o)) >\
	norm(op_vec3(op_vec3(inter->point, '-', inter->normal), '-', o)))
		inter->normal = opf_vec3(inter->normal, '*', -1);
	i = 0;
	while (i < 3)
	{
		inter->rgb[i] = tri->rgb[i];
		i++;
	}
}

void	get_norm_cyl(t_inter *inter, t_cyl *cyl, t_vec3 o)
{
	t_vec3	ctop;
	t_vec3	qtop;
	double	radius;
	t_vec3	half;

	half = op_vec3(cyl->o, '+', opf_vec3(cyl->d, '*', cyl->h / 2));
	ctop = op_vec3(inter->point, '-', half);
	radius = dot(ctop, cyl->d);
	qtop = op_vec3(ctop, '-', opf_vec3(cyl->d, '*', radius));
	inter->normal = normalize(opf_vec3(qtop, '/', cyl->r));
	if (norm(op_vec3(op_vec3(inter->point, '+', inter->normal), '-', o)) >\
	norm(op_vec3(op_vec3(inter->point, '-', inter->normal), '-', o)))
		inter->normal = opf_vec3(inter->normal, '*', -1);
}

void	get_inter_cyl(t_inter *inter, void *obj_inter, t_vec3 o)
{
	t_cyl	*cyl;
	t_vec3	half;
	int		i;

	cyl = (t_cyl*)obj_inter;
	half = op_vec3(cyl->o, '+', opf_vec3(cyl->d, '*', cyl->h / 2));
	get_norm_cyl(inter, cyl, o);
	i = 0;
	while (i < 3)
	{
		inter->rgb[i] = cyl->rgb[i];
		i++;
	}
}
