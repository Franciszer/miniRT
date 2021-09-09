/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckeckfull_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:55:29 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 19:05:01 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		check_alight(t_list *alight_list)
{
	t_alight	*alight;
	int			len;

	if (alight_list)
	{
		len = ft_lstlen(alight_list);
		if (len > 1)
			return (0);
		alight = (t_alight*)alight_list->content;
		if (alight->brightness > 1 || alight->brightness < 0)
			return (0);
	}
	return (1);
}

int		check_cam(t_list *cam_list)
{
	t_list	*nav;
	t_cam	*cam;

	nav = cam_list;
	if (!cam_list)
		return (0);
	while (nav)
	{
		cam = (t_cam*)nav->content;
		if (norm(cam->d) > 1 + EPS || norm(cam->d) < 1 - EPS)
			return (0);
		nav = nav->next;
	}
	return (1);
}

int		check_light(t_list *light_list)
{
	t_list	*nav;
	t_light	*light;

	nav = light_list;
	while (nav)
	{
		light = (t_light*)nav->content;
		if (light->brightness < 0 || light->brightness > 1)
			return (0);
		nav = nav->next;
	}
	return (1);
}

int		check_plane(t_list *plane_list)
{
	t_list	*nav;
	t_plane	*plane;

	nav = plane_list;
	while (nav)
	{
		plane = (t_plane*)nav->content;
		if (norm(plane->d) != 1)
			return (0);
		nav = nav->next;
	}
	return (1);
}

int		check_cyl(t_list *cyl_list)
{
	t_list	*nav;
	t_cyl	*cyl;

	nav = cyl_list;
	while (nav)
	{
		cyl = (t_cyl*)nav->content;
		if (norm(cyl->d) != 1)
			return (0);
		nav = nav->next;
	}
	return (1);
}
