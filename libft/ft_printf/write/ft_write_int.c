/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:57:50 by frthierr          #+#    #+#             */
/*   Updated: 2019/11/11 13:46:44 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_write_int(long d, char *buffer, int *i)
{
	unsigned int a;

	if (d < 0)
	{
		ft_print('-', buffer, i);
		a = (unsigned int)(d * -1);
	}
	else
		a = (unsigned int)d;
	if (a > 9)
	{
		ft_write_int((int)(a / 10), buffer, i);
		ft_write_int((int)(a % 10), buffer, i);
	}
	else
		ft_print((a + '0'), buffer, i);
}
