/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_axis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:26:43 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:42:20 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3		get_axis(t_vec3 u, t_vec3 normal)
{
	t_vec3	proj;

	proj = op_vec3(u, '-', opf_vec3(normal, '*',\
	(dot(u, normal) / norm2(normal))));
	if (!proj.x && !proj.y && !proj.x)
	{
		if (!u.x && u.y == 1 && !u.x)
			return (get_axis(get_vec3(1, 0, 0), normal));
		return (get_axis(get_vec3(0, 1, 0), normal));
	}
	return (normalize(proj));
}
