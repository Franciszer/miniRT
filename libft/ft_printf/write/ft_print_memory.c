/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 19:13:20 by frthierr          #+#    #+#             */
/*   Updated: 2019/11/12 10:37:51 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		ft_rprint_memory(t_param param, int len, char *buffer, int *i)
{
	if (param.value < 0)
		param.width--;
	if (param.prec > len)
		param.width -= param.prec - len;
	while (param.width - 2 > len && (param.flag != '0'\
		|| param.prec > INITPREC))
	{
		ft_print(' ', buffer, i);
		param.width--;
	}
	ft_print('0', buffer, i);
	ft_print('x', buffer, i);
	while ((param.width > len + 2 && param.flag == '0') || param.prec > len)
	{
		ft_print('0', buffer, i);
		param.width--;
		param.prec--;
	}
	if (param.prec != 0 || param.value)
		ft_write_hex(param.value, buffer, i, HEX_LOWER);
}

static void		ft_lprint_memory(t_param param, int len, char *buffer, int *i)
{
	ft_print('0', buffer, i);
	ft_print('x', buffer, i);
	while (param.prec > len)
	{
		ft_print('0', buffer, i);
		param.prec--;
		param.width--;
	}
	ft_write_hex(param.value, buffer, i, HEX_LOWER);
	while (param.width > len + 2)
	{
		ft_print(' ', buffer, i);
		param.width--;
	}
}

void			ft_print_memory(t_param param, int len, char *buffer, int *i)
{
	if (param.flag == '-' || param.flag == '-' + '0')
		ft_lprint_memory(param, len, buffer, i);
	else
		ft_rprint_memory(param, len, buffer, i);
}
