/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:35:33 by frthierr          #+#    #+#             */
/*   Updated: 2019/10/24 14:35:34 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	size_t			i;

	i = 0;
	dest = NULL;
	if (!s || !f)
		return (NULL);
	if (!(dest = (char *)malloc(ft_strlen((char *)s) * sizeof(char) + 1)))
		return (NULL);
	while (i < ft_strlen((char *)s))
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
