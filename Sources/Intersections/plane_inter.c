/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:53:11 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:40:59 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_inter		plane_iter(t_list *plane_list, t_vec3 cam_o, t_vec3 d,\
						t_inter inter_min)
{
	t_list		*nav;
	t_plane		*plane;
	t_inter		inter_curr;

	nav = plane_list;
	while (nav)
	{
		plane = (t_plane*)nav->content;
		inter_curr = plane_inter(plane, cam_o, d);
		if (inter_curr.d_to_o != INIT_D && (inter_min.d_to_o == INIT_D ||\
			inter_curr.d_to_o < inter_min.d_to_o))
			inter_min = inter_curr;
		nav = nav->next;
	}
	return (inter_min);
}

t_inter		plane_inter(t_plane *plane, t_vec3 o, t_vec3 d)
{
	double	t;
	double	nominator;
	double	denominator;

	denominator = dot(d, normalize(plane->d));
	if (ft_fabs(denominator))
	{
		nominator = dot((op_vec3(plane->o, '-', o)), normalize(plane->d));
		t = nominator / denominator;
		if (t > 0)
		{
			return (get_inter(op_vec3(o, '+', (opf_vec3(d, '*', t)))\
			, o, PLANE, (void*)plane));
		}
	}
	return (get_inter(o, o, 0, NULL));
}
