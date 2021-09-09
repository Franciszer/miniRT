/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:21:10 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:41:45 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	sq_to_tri(t_square sq, t_vec3 *sq_pt, t_tri **t, t_tri **t1)
{
	if (!((*t) = malloc(sizeof(t_tri))))
		return (0);
	if (!((*t1) = malloc(sizeof(t_tri))))
		return (0);
	(*t)->a = sq_pt[0];
	(*t)->b = sq_pt[2];
	(*t)->c = sq_pt[1];
	(*t1)->a = sq_pt[1];
	(*t1)->b = sq_pt[3];
	(*t1)->c = sq_pt[0];
	(*t)->rgb[0] = sq.rgb[0];
	(*t)->rgb[1] = sq.rgb[1];
	(*t)->rgb[2] = sq.rgb[2];
	(*t1)->rgb[0] = sq.rgb[0];
	(*t1)->rgb[1] = sq.rgb[1];
	(*t1)->rgb[2] = sq.rgb[2];
	return (1);
}

static int	add_square(t_obj *obj, t_square sq, t_vec3 yax)
{
	t_vec3	sq_pt[4];
	t_vec3	xax;
	t_list	*new;
	t_tri	*t;
	t_tri	*t1;

	if (!yax.x && !yax.y && !yax.z)
		yax = get_axis(get_vec3(0, 0, 1), sq.n);
	xax = normalize(cross_vec3(yax, sq.n));
	sq_pt[0] = op_vec3(sq.o, '+', opf_vec3(yax, '*', (sq.side * sqrt(2)) / 2));
	sq_pt[1] = op_vec3(sq.o, '-', opf_vec3(yax, '*', (sq.side * sqrt(2)) / 2));
	sq_pt[2] = op_vec3(sq.o, '+', opf_vec3(xax, '*', (sq.side * sqrt(2)) / 2));
	sq_pt[3] = op_vec3(sq.o, '-', opf_vec3(xax, '*', (sq.side * sqrt(2)) / 2));
	if (!sq_to_tri(sq, sq_pt, &t, &t1))
		return (0);
	if (!(new = ft_lstnew((void*)t)))
		return (0);
	ft_lstadd_front(&obj->tri_list, new);
	if (!(new = ft_lstnew((void*)t1)))
		return (0);
	ft_lstadd_front(&obj->tri_list, new);
	return (1);
}

int			get_square(double *vals, t_obj *obj)
{
	t_square	sq;

	sq.o.x = vals[0];
	sq.o.y = vals[1];
	sq.o.z = vals[2];
	sq.n.x = vals[3];
	sq.n.y = vals[4];
	sq.n.z = vals[5];
	sq.side = vals[6];
	sq.rgb[0] = (unsigned char)vals[7];
	sq.rgb[1] = (unsigned char)vals[8];
	sq.rgb[2] = (unsigned char)vals[9];
	sq.n = normalize(sq.n);
	add_square(obj, sq, get_vec3(0, 0, 0));
	if (norm(sq.n) != 1)
		return (0);
	return (1);
}
