/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:08:17 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:40:37 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	check_normal(t_inter *inter, t_light *light)
{
	t_vec3	to_light;
	t_vec3	inv_norm;

	inv_norm = opf_vec3(inter->normal, '*', -1);
	to_light = op_vec3(light->o, '-', inter->point);
	if (dot(to_light, inter->normal) <\
	dot(to_light, opf_vec3(inter->normal, '*', -1)))
		inter->normal = inv_norm;
}

static void	get_pixel_light(double *p_intensity, t_obj *obj, t_inter *inter)
{
	int		i;
	double	p_brightness;
	t_list	*nav;
	t_light	*light;

	nav = obj->light_list;
	while (nav)
	{
		light = (t_light*)nav->content;
		i = -1;
		p_brightness = 0;
		check_normal(inter, light);
		if (is_clearpath(obj, op_vec3(inter->point, '+',\
		opf_vec3(inter->normal, '*', EPS)), light))
		{
			p_brightness = dot(normalize(op_vec3(light->o, '-', inter->point))\
			, inter->normal) / norm2(op_vec3(light->o, '-', inter->point));
		}
		if (p_brightness < 0)
			p_brightness = 0;
		while (++i < 3)
			p_intensity[i] += 10 * p_brightness * light->brightness *\
			(double)light->rgb[i] * (double)inter->rgb[i];
		nav = nav->next;
	}
}

static void	get_pixel_alight(double *p_intensity, t_obj *obj, t_inter *inter)
{
	t_list		*nav;
	t_alight	*alight;
	double		pixel_light;
	int			i;

	nav = obj->alight_list;
	if (nav)
	{
		alight = (t_alight*)nav->content;
		if (alight)
		{
			i = 0;
			while (i < 3)
			{
				pixel_light = alight->brightness * (double)alight->rgb[i]\
				* (double)inter->rgb[i];
				if (pixel_light < 0)
					pixel_light = 0;
				p_intensity[i] = pixel_light / 10;
				i++;
			}
		}
	}
}

void		light_pixel(t_obj *obj, t_inter *inter)
{
	double		p_intensity[3];
	int			i;

	ft_bzero((void*)p_intensity, sizeof(double) * 3);
	get_pixel_alight(p_intensity, obj, inter);
	get_pixel_light(p_intensity, obj, inter);
	i = 0;
	while (i < 3)
	{
		if (p_intensity[i] > 255)
			p_intensity[i] = 255;
		if (p_intensity[i] < 0)
			p_intensity[i] = 0;
		inter->rgb[i] = (unsigned char)p_intensity[i];
		i++;
	}
}

void		get_canvas_light(t_obj *obj, int w, int h, t_inter **inter)
{
	int	i;
	int	j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			light_pixel(obj, &inter[i][j]);
			j++;
		}
		i++;
	}
}
