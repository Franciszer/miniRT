/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:04:05 by franciszer        #+#    #+#             */
/*   Updated: 2020/02/22 18:40:23 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int		get_bmpname(char **name)
{
	static int		n;
	char			*sn;

	if (!(sn = ft_itoa(n++)))
		return (0);
	if (!(*name = ft_strjoin(IMG_DIR, sn)))
		return (0);
	if (!(*name = ft_strjoin_free(*name, ".bmp")))
		return (0);
	free(sn);
	return (1);
}

static void		write_header_bmp(int fd, t_obj *obj)
{
	static unsigned char	header[54] = {66, 77, 0, 0, 0, 0, 0, 0, 0, 0, 54, \
		0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24};
	unsigned int			*filesize;
	unsigned int			*width;
	unsigned int			*height;

	filesize = (unsigned int*)&header[2];
	*filesize = 54 + (obj->res->x * sizeof(char) + (4 - \
						((obj->res->x * sizeof(char)) % 4)) % 4) * obj->res->y;
	width = (unsigned int *)&header[18];
	*width = (unsigned int)obj->res->x;
	height = (unsigned int *)&header[22];
	*height = (unsigned int)obj->res->y;
	write(fd, header, 54);
}

static int		write_imgdata(t_obj *obj, unsigned char *img_data, int fd)
{
	int						i;
	int						j;
	static unsigned char	zeroes[3] = {0, 0, 0};
	int						z;

	j = obj->res->y;
	z = 0;
	while (j--)
	{
		i = 0;
		while (i < obj->res->x)
		{
			write(fd, &img_data[z++], sizeof(char));
			write(fd, &img_data[z++], sizeof(char));
			write(fd, &img_data[z++], sizeof(char));
			i++;
		}
		write(fd, zeroes, (4 - ((obj->res->x * sizeof(char)) % 4)) % 4);
	}
	return (1);
}

int				write_bmp(t_obj *obj)
{
	int				fd;
	char			*name;
	unsigned char	*img_data;
	t_list			*nav;

	nav = obj->inter_list;
	while (nav)
	{
		if (!get_bmpname(&name))
			return (0);
		if ((fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, \
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) < 1)
		{
			return (0);
		}
		write_header_bmp(fd, obj);
		if (!(img_data = (unsigned char*)inter_to_char(obj,\
		(t_inter**)nav->content)))
			return (0);
		write_imgdata(obj, img_data, fd);
		nav = nav->next;
		free(img_data);
		free(name);
	}
	return (1);
}
