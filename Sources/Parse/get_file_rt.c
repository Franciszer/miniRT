/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_rt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:20:12 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:41:58 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char		**lst_to_str(t_list *file_lst)
{
	char	**file;
	int		size;
	t_list	*nav;
	int		i;

	size = ft_lstsize(file_lst);
	if (!(file = (char **)malloc(sizeof(char *) * (size + 1))))
		return ((char **)0);
	nav = file_lst;
	i = 0;
	while (i < size)
	{
		if (!(file[i] = ft_strdup((const char *)nav->content)))
			return ((char **)0);
		nav = nav->next;
		i++;
	}
	file[i] = (char *)0;
	return (file);
}

static char		**end_function(t_list **file_lst, char *line)
{
	char	**file;

	if (!(file = lst_to_str(*file_lst)))
		return ((char**)0);
	ft_lstclear(file_lst, free);
	free(line);
	return (file);
}

char			**get_file_rt(char *filename)
{
	int			fd;
	t_list		*file_lst;
	t_list		*data;
	char		*line;

	fd = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return ((char **)0);
	if (read(fd, NULL, 0) < 0)
		return ((char **)0);
	file_lst = NULL;
	while (get_next_line(fd, &line) > 0 || line[0])
	{
		if (line[0] && line[0] != '\n')
		{
			if (!(data = ft_lstnew((void *)line)))
				return ((char **)0);
			ft_lstadd_front(&file_lst, data);
		}
		else
			free(line);
	}
	return (end_function(&file_lst, line));
}
