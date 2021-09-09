/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_rt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:11:28 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:41:16 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int		g_size_line;
int		g_bpp;
int		g_endian;

int		deal_key(int key, void *param)
{
	t_data	*data;

	data = (t_data*)param;
	if (key == 53)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		free_obj_rt(data->obj);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	if (key == 48)
	{
		data->inter_n[0]++;
		get_img_rt(data->cols, data->obj,\
				which_inter(data->obj->inter_list, data->inter_n), data);
	}
	return (1);
}

void	init_mlxdata(t_data *data, t_obj *obj)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,\
		obj->res->x, obj->res->y, "miniRT");
}

void	get_img_rt(unsigned char *colors, t_obj *obj,\
		t_inter **inter, t_data *data)
{
	int	i;
	int	j;
	int	z;
	int	x;
	int	y;

	i = 0;
	z = 0;
	x = (int)obj->res->x;
	y = (int)obj->res->y;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			*colors++ = inter[i][j].rgb[2];
			*colors++ = inter[i][j].rgb[1];
			*colors++ = inter[i][j].rgb[0];
			*colors++ = 0;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

int		end(void *param)
{
	deal_key(53, param);
	return (0);
}

int		display_rt(t_obj *obj)
{
	t_data	data;
	t_inter	**inter;
	int		inter_n;

	init_mlxdata(&data, obj);
	inter_n = 0;
	data.inter_n = &inter_n;
	data.img_ptr = mlx_new_image(data.mlx_ptr,\
			(int)obj->res->x, (int)obj->res->y);
	data.cols = (unsigned char*)mlx_get_data_addr(data.img_ptr,\
			&g_bpp, &g_size_line, &g_endian);
	data.obj = obj;
	if (!(get_inters_rt(obj)))
		return (0);
	inter = which_inter(obj->inter_list, data.inter_n);
	get_img_rt(data.cols, obj, inter, &data);
	mlx_hook(data.win_ptr, 17, 1L << 0, end, &data);
	mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_loop(data.mlx_ptr);
	return (1);
}
