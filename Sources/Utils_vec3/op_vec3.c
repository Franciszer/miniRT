/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_vec3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:18:29 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:42:34 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec3	add_vec3(t_vec3 v, t_vec3 w)
{
	t_vec3		y;

	y.x = v.x + w.x;
	y.y = v.y + w.y;
	y.z = v.z + w.z;
	return (y);
}

static t_vec3	diff_vec3(t_vec3 v, t_vec3 w)
{
	t_vec3		y;

	y.x = v.x - w.x;
	y.y = v.y - w.y;
	y.z = v.z - w.z;
	return (y);
}

static t_vec3	mult_vec3(t_vec3 v, t_vec3 w)
{
	t_vec3		y;

	y.x = v.x * w.x;
	y.y = v.y * w.y;
	y.z = v.z * w.z;
	return (y);
}

static t_vec3	div_vec3(t_vec3 v, t_vec3 w)
{
	t_vec3		y;

	if (!w.x || !w.y || !w.z)
		return (get_vec3(0, 0, 0));
	y.x = v.x / w.x;
	y.y = v.y / w.y;
	y.z = v.z / w.z;
	return (y);
}

t_vec3			op_vec3(t_vec3 v, char op, t_vec3 w)
{
	if (op == '+')
		return (add_vec3(v, w));
	else if (op == '-')
		return (diff_vec3(v, w));
	else if (op == '*')
		return (mult_vec3(v, w));
	else if (op == '/')
		return (div_vec3(v, w));
	else
		return (get_vec3(0, 0, 0));
}
