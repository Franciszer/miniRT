/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vals_rt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:50:11 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:42:02 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int		get_nvals(int id)
{
	if (id == RES)
		return (RES_NVALS);
	else if (id == ALIGHT)
		return (ALIGHT_NVALS);
	else if (id == CAM)
		return (CAM_NVALS);
	else if (id == LIGHT)
		return (LIGHT_NVALS);
	else if (id == SPHERE)
		return (SPHERE_NVALS);
	else if (id == PLANE)
		return (PLANE_NVALS);
	else if (id == SQUARE)
		return (SQUARE_NVALS);
	else if (id == CY)
		return (CY_NVALS);
	else if (id == TRI)
		return (TRI_NVALS);
	else
		return (0);
}

static double	*line_to_vals(char *line, int id)
{
	int		size;
	double	*vals;
	char	**args;
	int		i;
	int		j;

	size = get_nvals(id);
	if (!(vals = (double *)malloc(sizeof(double) * size)))
		return ((double *)0);
	if (!(args = ft_split_charset(line, " ,")))
		return ((double *)free_return((void**)&vals));
	i = 0;
	j = 0;
	while (args[i])
	{
		if (ft_isdouble(args[i]))
		{
			vals[j] = ft_atof(args[i]);
			j++;
		}
		i++;
	}
	free_strtab(args);
	return (vals);
}

static int		get_obj(double *vals, int id, t_obj *obj)
{
	if (id == RES)
		return (get_res(vals, obj));
	else if (id == CAM)
		return (get_cam(vals, obj));
	else if (id == ALIGHT)
		return (get_alight(vals, obj));
	else if (id == LIGHT)
		return (get_light(vals, obj));
	else if (id == SPHERE)
		return (get_sphere(vals, obj));
	else if (id == PLANE)
		return (get_plane(vals, obj));
	else if (id == SQUARE)
		return (get_square(vals, obj));
	else if (id == CY)
		return (get_cyl(vals, obj));
	else if (id == TRI)
		return (get_triangle(vals, obj));
	else
		return (0);
}

int				get_vals_rt(char **file, int i, int id, t_obj *obj)
{
	double	*vals;

	if (!(vals = (double*)line_to_vals(file[i], id)))
		return (0);
	if (!(get_obj(vals, id, obj)))
		return (0);
	if (vals)
		free(vals);
	return (1);
}
