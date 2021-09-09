/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:38:00 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/20 14:30:50 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *desc, const void *src, size_t size)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *)desc;
	s = (unsigned char *)src;
	if ((desc == NULL) || (src == NULL))
		return (NULL);
	while (size-- > 0)
	{
		*d = *s;
		d++;
		s++;
	}
	return (desc);
}
