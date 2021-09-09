/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_vec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:56:02 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:42:43 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec3	calculate_rot(t_vec3 *c2, t_vec3 *c3, t_vec3 rot, t_vec3 to)
{
	t_vec3	c1;
	t_vec3	v;
	float	c;
	float	s;
	float	r;

	v = cross_vec3(to, rot);
	c = dot(rot, to);
	s = pow(norm(v), 2);
	r = ((1 - c) / s);
	c1 = get_vec3(-r * (pow(v.y, 2) + pow(v.z, 2)) + 1, r * v.x * \
				v.y - v.z, r * v.x * v.z + v.y);
	(*c2) = get_vec3(r * v.x * v.y + v.z, -r * (pow(v.x, 2) + \
					pow(v.z, 2)) + 1, r * v.y * v.x - v.x);
	(*c3) = get_vec3(r * v.x * v.z - v.y, r * v.y * v.z - v.x, -r * \
					(pow(v.x, 2) + pow(v.y, 2)) + 1);
	return (c1);
}

t_vec3			rot_vec3(t_vec3 pos, t_vec3 dir, t_vec3 rot)
{
	t_vec3	c1;
	t_vec3	c2;
	t_vec3	c3;
	t_vec3	prev;

	if (dir.x == 0 && dir.y == 0 && dir.z < 0)
	{
		pos.z *= -1;
		return (pos);
	}
	else if (!(dir.x == 0 && dir.y == 0 && dir.z != 0))
	{
		prev = pos;
		c1 = calculate_rot(&c2, &c3, rot, dir);
		pos = get_vec3(-dot(c1, prev), -dot(c2, prev), -dot(c3, prev));
	}
	return (pos);
}
