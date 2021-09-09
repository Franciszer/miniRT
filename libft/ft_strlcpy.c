/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:35:59 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/19 13:07:26 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (--size && src[i])
	{
		dest[i] = src[i];
		ft_putendl_fd(ft_itoa(dest[i]), 1);
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
