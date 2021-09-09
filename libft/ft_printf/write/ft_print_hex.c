/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:21:11 by frthierr          #+#    #+#             */
/*   Updated: 2019/11/12 14:27:56 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void			ft_rprint_hex(t_param param, int len, char *buffer, int *i)
{
	while (param.width > len && (param.flag != '0' || param.prec > INITPREC)\
			&& param.width > param.prec)
	{
		ft_print(' ', buffer, i);
		param.width--;
	}
	while ((param.width > len && param.flag == '0') || param.prec > len)
	{
		ft_print('0', buffer, i);
		param.width--;
		param.prec--;
	}
	ft_write_param(param, buffer, i);
}

static void			ft_lprint_hex(t_param param, int len, char *buffer, int *i)
{
	if (!param.value && param.prec >= 0)
		len = 0;
	while (param.prec > len)
	{
		ft_print('0', buffer, i);
		param.prec--;
		param.width--;
	}
	ft_write_param(param, buffer, i);
	param.width -= len;
	while (param.width > 0)
	{
		ft_print(' ', buffer, i);
		param.width--;
	}
}

void				ft_print_hex(t_param param, int len, char *buffer, int *i)
{
	if (param.value < 0)
		param.value *= -1;
	if (param.flag == '-' || param.flag == '-' + '0')
		ft_lprint_hex(param, len, buffer, i);
	else
		ft_rprint_hex(param, len, buffer, i);
}
