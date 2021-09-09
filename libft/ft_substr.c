/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:34:24 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/20 00:40:25 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	int		temp;
	size_t	length;
	char	*res;

	length = ft_strlen(s);
	if (length <= start)
	{
		if (!(res = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	temp = start;
	i = -1;
	while (++i < len && s[temp])
		temp++;
	if (!(res = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (i < len && s[start])
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
