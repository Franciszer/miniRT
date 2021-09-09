/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:37:34 by frthierr          #+#    #+#             */
/*   Updated: 2019/11/26 09:52:53 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_clear_line(char **s)
{
	size_t	linelen;
	size_t	len;
	size_t	i;
	char	*tmp;

	linelen = ft_linelen(s[0]);
	len = ft_strlen((const char *)s[0]);
	tmp = NULL;
	if (linelen + 1 < len)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (len + 1))))
			return (0);
		i = -1;
		if (s[0][linelen] == '\n')
			linelen++;
		while (++i + linelen < len)
			tmp[i] = s[0][i + linelen];
		tmp[i] = 0;
	}
	if (s[0])
		free(s[0]);
	s[0] = tmp;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*s;
	char		buffer[BUFFER_SIZE];
	int			red;

	red = 1;
	if (!s && read(fd, NULL, 0) < 0)
		return (-1);
	while (red && !ft_isline(s))
	{
		red = read(fd, buffer, BUFFER_SIZE);
		if (!(ft_add_buffer(&s, buffer, red)))
			return (-1);
	}
	if (!ft_getline(s, line))
		return (-1);
	if (!ft_clear_line(&s))
		return (0);
	if (!red && !ft_isline(s))
		return (0);
	return (1);
}
