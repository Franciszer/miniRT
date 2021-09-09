/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:40:12 by frthierr          #+#    #+#             */
/*   Updated: 2019/10/24 14:40:25 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t eltsize)
{
	size_t	size;
	void	*value;

	size = count * eltsize;
	if (!(value = malloc(size)))
		return (NULL);
	if (value != 0)
		ft_memset(value, 0, size);
	return (value);
}
