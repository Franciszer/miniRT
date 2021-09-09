/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_parse_rt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:24:26 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:41:53 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*free_strtab(char **file)
{
	int i;

	i = 0;
	while (file[i])
	{
		free(file[i]);
		i++;
	}
	free(file);
	return (NULL);
}

void	*free_return(void **p)
{
	if (p)
		free(p[0]);
	return (NULL);
}

void	*free_obj_rt(t_obj *obj)
{
	if (obj->inter_list)
		free_inter_list(obj->inter_list, obj);
	if (obj->res)
		free(obj->res);
	ft_lstclear(&obj->cam_list, free);
	ft_lstclear(&obj->alight_list, free);
	ft_lstclear(&obj->light_list, free);
	ft_lstclear(&obj->sphere_list, free);
	ft_lstclear(&obj->plane_list, free);
	ft_lstclear(&obj->cyl_list, free);
	ft_lstclear(&obj->tri_list, free);
	free(obj);
	return (NULL);
}

void	*exit_parse_rt(char *msg, t_obj *obj, char **file)
{
	print_error(msg);
	if (file)
		free_strtab(file);
	if (obj)
		free_obj_rt(obj);
	return (0);
}
