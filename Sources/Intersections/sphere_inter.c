/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:27:25 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:41:06 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_inter		sphere_iter(t_list *sphere_list, t_vec3 cam_o, t_vec3 d,\
						t_inter inter_min)
{
	t_list		*nav;
	t_sphere	*sphere;
	t_inter		inter_curr;

	nav = sphere_list;
	while (nav)
	{
		sphere = (t_sphere*)nav->content;
		inter_curr = sphere_inter(sphere, cam_o, d);
		if (inter_curr.d_to_o != INIT_D && (inter_min.d_to_o == INIT_D ||\
									inter_curr.d_to_o < inter_min.d_to_o))
			inter_min = inter_curr;
		nav = nav->next;
	}
	return (inter_min);
}

t_inter		sphere_inter(t_sphere *s, t_vec3 cam_o, t_vec3 d)
{
	double	b;
	double	c;
	double	delta;
	double	t1;
	double	t2;

	b = 2 * dot(d, op_vec3(cam_o, '-', s->c));
	c = norm2(op_vec3(cam_o, '-', s->c)) - pow(s->diameter / 2, 2);
	if ((delta = pow(b, 2) - 4 * c) >= 0)
	{
		t1 = (-b - sqrt(delta)) / 2;
		t2 = (-b + sqrt(delta)) / 2;
		if (t1 > 0)
			return (get_inter(op_vec3(cam_o, '+', opf_vec3(d, '*', t1))\
					, cam_o, SPHERE, s));
		else if (t2 > 0)
			return (get_inter(op_vec3(cam_o, '+', opf_vec3(d, '*', t2))\
					, cam_o, SPHERE, s));
	}
	return (get_inter(cam_o, cam_o, 0, NULL));
}
