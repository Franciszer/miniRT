/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:49:31 by frthierr          #+#    #+#             */
/*   Updated: 2019/11/12 14:28:37 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_write_uint(unsigned int d, char *buffer, int *i)
{
	if (d > 9)
	{
		ft_write_int((int)(d / 10), buffer, i);
		ft_write_int((int)(d % 10), buffer, i);
	}
	else
		ft_print((d + '0'), buffer, i);
}
