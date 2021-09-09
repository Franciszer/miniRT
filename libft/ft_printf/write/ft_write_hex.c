/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:14:44 by frthierr          #+#    #+#             */
/*   Updated: 2019/11/12 15:55:38 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_write_hex(unsigned long d, char *buffer, int *i, char *base)
{
	unsigned long	baselen;

	baselen = 16;
	if (d + 1 > baselen)
	{
		ft_write_hex((d / baselen), buffer, i, base);
		ft_write_hex((d % baselen), buffer, i, base);
	}
	else
		ft_print(base[d], buffer, i);
}
