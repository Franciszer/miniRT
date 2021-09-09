/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:36:20 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/15 17:57:55 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	if (!str1 || !str2)
		return (NULL);
	if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen(str1) +\
	ft_strlen(str2) + 1))))
		return (NULL);
	while (*str1)
		dest[i++] = *str1++;
	while (*str2)
	{
		dest[i] = *str2;
		i++;
		str2++;
	}
	dest[i] = '\0';
	return (dest);
}
