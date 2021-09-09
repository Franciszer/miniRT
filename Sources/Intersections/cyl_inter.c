/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:42:10 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:40:42 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_inter			cyl_iter(t_list *cyl_list, t_vec3 cam_o, t_vec3 d,\
					t_inter inter_min)
{
	t_list		*nav;
	t_cyl		*cyl;
	t_inter		inter_curr;

	nav = cyl_list;
	while (nav)
	{
		cyl = (t_cyl*)nav->content;
		inter_curr = cyl_inter(cyl, cam_o, d);
		if (inter_curr.d_to_o != INIT_D && (inter_min.d_to_o == INIT_D ||\
									inter_curr.d_to_o < inter_min.d_to_o))
			inter_min = inter_curr;
		nav = nav->next;
	}
	return (inter_min);
}

static t_inter	get_inter_norminette(double *vals, t_vec3 o, t_vec3 d,\
									t_cyl *cyl)
{
	return (get_inter(op_vec3(o, '+', \
	opf_vec3(d, '*', vals[8])), o, CY, (void*)cyl));
}

static t_inter	get_inter_norminette1(double *vals,\
				t_vec3 o, t_vec3 d, t_cyl *cyl)
{
	if (vals[4] > 0 && vals[4] < vals[0] && vals[8] > 0)
	{
		return (get_inter(op_vec3(o, '+', \
		opf_vec3(d, '*', vals[8])), o, CY, (void*)cyl));
	}
	return (get_inter(o, o, 0, NULL));
}

t_inter			cyl_inter(t_cyl *cyl, t_vec3 o, t_vec3 d)
{
	t_vec3	vvals[2];
	double	vals[9];

	vvals[0] = op_vec3(op_vec3(cyl->o, '+', \
			opf_vec3(cyl->d, '*', cyl->h)), '-', cyl->o);
	vvals[1] = op_vec3(o, '-', cyl->o);
	vals[0] = dot(vvals[0], vvals[0]);
	vals[1] = dot(vvals[0], d);
	vals[2] = dot(vvals[0], vvals[1]);
	vals[5] = vals[0] - pow(vals[1], 2);
	vals[6] = vals[0] * dot(vvals[1], d) - (vals[2] * vals[1]);
	vals[7] = vals[0] * dot(vvals[1], vvals[1]) - \
	pow(vals[2], 2) - ((pow(cyl->r, 2)) * vals[0]);
	vals[3] = pow(vals[6], 2) - (vals[5] * vals[7]);
	if (vals[3] < 0)
		return (get_inter(o, o, 0, NULL));
	vals[3] = sqrt(vals[3]);
	vals[8] = (-vals[6] - vals[3]) / vals[5];
	vals[4] = vals[2] + vals[8] * vals[1];
	if (vals[4] > 0 && vals[4] < vals[0] && vals[8] > 0)
		return (get_inter_norminette(vals, o, d, cyl));
	vals[8] = (-vals[6] + vals[3]) / vals[5];
	vals[4] = vals[2] + vals[8] * vals[1];
	return (get_inter_norminette1(vals, o, d, cyl));
}
