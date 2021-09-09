/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:37:45 by frthierr          #+#    #+#             */
/*   Updated: 2019/10/24 14:40:25 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	value;
	size_t			size;

	if (str == NULL)
		return (NULL);
	value = (unsigned char)c;
	size = 0;
	while (size < n)
	{
		((char *)str)[size] = value;
		size++;
	}
	return (str);
}
