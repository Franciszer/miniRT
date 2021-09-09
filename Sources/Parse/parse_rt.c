/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:48:08 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:42:06 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		is_rtfile(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	i--;
	if (i + 1 > 2)
	{
		if (filename[i--] == 't' && filename[i--] == 'r' &&\
			filename[i] == '.')
			return (1);
	}
	print_error("Not an .rt file\n");
	return (0);
}

t_obj	*obj_init_rt(void)
{
	t_obj	*obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return ((t_obj *)0);
	obj->res = NULL;
	obj->cam_list = NULL;
	obj->alight_list = NULL;
	obj->light_list = NULL;
	obj->sphere_list = NULL;
	obj->plane_list = NULL;
	obj->cyl_list = NULL;
	obj->tri_list = NULL;
	obj->inter_list = NULL;
	return (obj);
}

t_obj	*parse_rt(char *filename)
{
	t_obj	*obj;
	char	**file;
	int		id;
	int		i;

	obj = NULL;
	file = NULL;
	if (!(obj = obj_init_rt()))
		return ((t_obj *)exit_parse_rt("", obj, file));
	if (!(file = get_file_rt(filename)))
		return ((t_obj *)exit_parse_rt("", obj, file));
	i = 0;
	while (file[i])
	{
		if (!(id = check_line_rt(file, i)))
			return ((t_obj *)exit_parse_rt("Line not valid\n", obj, file));
		if (!get_vals_rt(file, i, id, obj))
			return ((t_obj *)exit_parse_rt(ERR_NVALS, obj, file));
		i++;
	}
	if (!(checkfull_rt(obj)))
		return ((t_obj *)exit_parse_rt(ERR_VALS, obj, file));
	free_strtab(file);
	return (obj);
}
