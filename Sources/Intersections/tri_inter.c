/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:30:51 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:41:10 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_inter	tri_iter(t_list *tri_list, t_vec3 cam_o, t_vec3 d, t_inter inter_min)
{
	t_list		*nav;
	t_tri		*tri;
	t_inter		inter_curr;

	nav = tri_list;
	while (nav)
	{
		tri = (t_tri*)nav->content;
		inter_curr = tri_inter(tri, cam_o, d);
		if (inter_curr.d_to_o != INIT_D && (inter_min.d_to_o == INIT_D ||\
									inter_curr.d_to_o < inter_min.d_to_o))
			inter_min = inter_curr;
		nav = nav->next;
	}
	return (inter_min);
}

t_inter	tri_inter(t_tri *tri, t_vec3 o, t_vec3 d)
{
	t_vec3	edge[2];
	t_vec3	vvals[3];
	double	vals[4];
	double	t;

	edge[0] = op_vec3(tri->b, '-', tri->a);
	edge[1] = op_vec3(tri->c, '-', tri->a);
	vvals[0] = cross_vec3(d, edge[1]);
	vals[0] = dot(edge[0], vvals[0]);
	if (vals[0] > -EPS && vals[0] < EPS)
		return (get_inter(o, o, 0, NULL));
	vals[1] = 1.0 / vals[0];
	vvals[1] = op_vec3(o, '-', tri->a);
	vals[2] = vals[1] * dot(vvals[1], vvals[0]);
	if (vals[2] < 0.0 || vals[2] > 1.0)
		return (get_inter(o, o, 0, NULL));
	vvals[2] = cross_vec3(vvals[1], edge[0]);
	vals[3] = vals[1] * dot(d, vvals[2]);
	if (vals[3] < 0.0 || vals[2] + vals[3] > 1.0)
		return (get_inter(o, o, 0, NULL));
	t = vals[1] * dot(edge[1], vvals[2]);
	return (t > EPS ? get_inter(op_vec3(o, '+', opf_vec3(d, '*', t)), o, TRI\
	, (void*)tri) : get_inter(o, o, 0, NULL));
}
