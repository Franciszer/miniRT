/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_rt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:46:02 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:41:49 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	which_id_rt(const char *s)
{
	if (!ft_strncmp(s, "sp", 2))
		return (SPHERE);
	else if (!ft_strncmp(s, "pl", 2))
		return (PLANE);
	else if (!ft_strncmp(s, "sq", 2))
		return (SQUARE);
	else if (!ft_strncmp(s, "cy", 2))
		return (CY);
	else if (!ft_strncmp(s, "tr", 2))
		return (TRI);
	else if (!ft_strncmp(s, "R", 1))
		return (RES);
	else if (!ft_strncmp(s, "A", 1))
		return (ALIGHT);
	else if (!ft_strncmp(s, "c", 1))
		return (CAM);
	else if (!ft_strncmp(s, "l", 1))
		return (LIGHT);
	else
		return (0);
}

static int	check_id_rt(char **line)
{
	int	found;
	int	i;

	found = 0;
	i = 0;
	while (line[i])
	{
		if (ft_is_stralpha(line[i]))
		{
			if (found)
				return (print_error(ERR_ID_MUCH));
			found = which_id_rt((const char *)line[i]);
			if (!found)
				return (print_error(ERR_ID_NO));
		}
		i++;
	}
	return (found);
}

static int	nvals_rt(char **line)
{
	int		ct;
	int		i;
	char	**vec;

	i = 0;
	ct = 0;
	while (line[i])
	{
		if (!(ft_strchr((const char *)line[i], ',')))
		{
			if (ft_isdouble(line[i]) ||\
				(line[i][0] == '-' && ft_isdouble(&line[i][1])))
				ct++;
		}
		else
		{
			if (!(vec = ft_split((const char *)line[i], ',')))
				return (0);
			ct += nvals_rt(vec);
			free_strtab(vec);
		}
		i++;
	}
	return (ct);
}

static int	ft_check_vals(char **line, int id)
{
	int		n;

	n = nvals_rt(line);
	if (id == RES && n == RES_NVALS)
		return (1);
	else if (id == ALIGHT && n == ALIGHT_NVALS)
		return (1);
	else if (id == CAM && n == CAM_NVALS)
		return (1);
	else if (id == LIGHT && n == LIGHT_NVALS)
		return (1);
	else if (id == SPHERE && n == SPHERE_NVALS)
		return (1);
	else if (id == PLANE && n == PLANE_NVALS)
		return (1);
	else if (id == SQUARE && n == SQUARE_NVALS)
		return (1);
	else if (id == CY && n == CY_NVALS)
		return (1);
	else if (id == TRI && n == TRI_NVALS)
		return (1);
	else
		return (0);
}

int			check_line_rt(char **file, int n_line)
{
	int		id;
	char	**line;

	id = 0;
	if (!(line = ft_split((const char *)file[n_line], ' ')))
		return (0);
	if (!(id = check_id_rt(line)) || !ft_check_vals(line, id))
	{
		free_strtab(line);
		return (0);
	}
	free_strtab(line);
	return (id);
}
