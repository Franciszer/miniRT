/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:09:16 by frthierr          #+#    #+#             */
/*   Updated: 2019/11/26 09:54:36 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_isline(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		ft_add_buffer(char **s, char *buffer, int red)
{
	int		len;
	char	*tmp;
	int		i;

	if (!buffer)
		return (1);
	len = (int)ft_strlen((const char *)s[0]);
	if (!(tmp = (char *)malloc(sizeof(char) * (len + red + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		tmp[i] = s[0][i];
		i++;
	}
	while (i - len < red)
	{
		tmp[i] = buffer[i - len];
		i++;
	}
	tmp[i] = '\0';
	if (s[0])
		free(s[0]);
	s[0] = tmp;
	return (1);
}

size_t	ft_linelen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int		ft_getline(char *s, char **line)
{
	size_t	len;
	size_t	i;

	len = ft_linelen(s);
	if (!(line[0] = malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		line[0][i] = s[i];
		i++;
	}
	line[0][i] = '\0';
	return (1);
}
