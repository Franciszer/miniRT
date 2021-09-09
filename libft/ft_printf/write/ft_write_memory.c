/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:58:21 by frthierr          #+#    #+#             */
/*   Updated: 2019/11/10 19:07:46 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_write_memory(void *p, char *buffer, int *i)
{
	long d;

	d = (long)p;
	ft_print('0', buffer, i);
	ft_print('x', buffer, i);
	ft_write_hex(d, buffer, i, HEX_LOWER);
}
