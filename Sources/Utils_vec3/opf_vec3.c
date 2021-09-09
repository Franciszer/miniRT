/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opf_vec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:01:52 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:42:38 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec3	fadd_vec3(t_vec3 v, double f)
{
	t_vec3		y;

	y.x = v.x + f;
	y.y = v.y + f;
	y.z = v.z + f;
	return (y);
}

static t_vec3	fdiff_vec3(t_vec3 v, double f)
{
	t_vec3		y;

	y.x = v.x - f;
	y.y = v.y - f;
	y.z = v.z - f;
	return (y);
}

static t_vec3	fmult_vec3(t_vec3 v, double f)
{
	t_vec3		y;

	y.x = v.x * f;
	y.y = v.y * f;
	y.z = v.z * f;
	return (y);
}

static t_vec3	fdiv_vec3(t_vec3 v, double f)
{
	t_vec3		y;

	if (!f || !f || !f)
		return (get_vec3(0, 0, 0));
	y.x = v.x / f;
	y.y = v.y / f;
	y.z = v.z / f;
	return (y);
}

t_vec3			opf_vec3(t_vec3 v, char op, double f)
{
	if (op == '+')
		return (fadd_vec3(v, f));
	else if (op == '-')
		return (fdiff_vec3(v, f));
	else if (op == '*')
		return (fmult_vec3(v, f));
	else if (op == '/')
		return (fdiv_vec3(v, f));
	else
		return (get_vec3(0, 0, 0));
}
