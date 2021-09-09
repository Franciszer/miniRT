/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:01:32 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:40:55 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_inter		get_inter(t_vec3 point, t_vec3 o, int id, void *obj_inter)
{
	t_inter	inter;
	int		i;

	inter.o = o;
	inter.point = point;
	inter.d_to_o = norm2(op_vec3(inter.point, '-', inter.o));
	if (id == 0)
	{
		inter.d_to_o = INIT_D;
		i = 0;
		while (i < 3)
			inter.rgb[i++] = 0;
	}
	else if (id == SPHERE)
		get_inter_sphere(&inter, obj_inter, o);
	else if (id == PLANE)
		get_inter_plane(&inter, obj_inter, o);
	else if (id == TRI)
		get_inter_tri(&inter, obj_inter, o);
	else if (id == CY)
		get_inter_cyl(&inter, obj_inter, o);
	return (inter);
}

t_inter		**free_inter(t_inter **inter, int h_max)
{
	int	i;

	i = 0;
	while (i < h_max)
	{
		free(inter[i]);
		i++;
	}
	free(inter);
	return ((t_inter**)0);
}

void		free_inter_list(t_list *list, t_obj *obj)
{
	t_list	*nav;
	t_list	*tmp;
	int		h;

	h = obj->res->y;
	nav = list;
	while (nav)
	{
		free_inter((t_inter**)nav->content, h);
		tmp = nav;
		nav = nav->next;
		free(tmp);
	}
}
