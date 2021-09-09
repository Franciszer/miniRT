/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:35:06 by frthierr          #+#    #+#             */
/*   Updated: 2019/10/24 14:35:07 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *c, size_t n)
{
	size_t i;
	size_t pos;
	size_t len;

	i = 0;
	len = 0;
	while (c[len] != '\0')
		len++;
	if (len == 0)
		return ((char *)str);
	while (str[i] && i <= n)
	{
		pos = 0;
		while (c[pos] == str[i + pos] && i + pos <= n)
		{
			if (pos == len - 1)
				return ((char *)str + i);
			pos++;
		}
		i++;
	}
	return (NULL);
}
