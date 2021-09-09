/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_widprec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:32:29 by frthierr          #+#    #+#             */
/*   Updated: 2019/11/12 11:16:54 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_widprec(t_param param, int len, char *buffer, int *i)
{
	if (param.value < 0)
		param.width--;
	while (param.width > len && (param.flag != '0' || param.prec > INITPREC)\
			&& param.width > param.prec)
	{
		ft_print(' ', buffer, i);
		param.width--;
	}
	if (param.value < 0)
	{
		param.value *= -1;
		ft_print('-', buffer, i);
	}
	while ((param.width > len && param.flag == '0') || param.prec > len)
	{
		ft_print('0', buffer, i);
		param.width--;
		param.prec--;
	}
	ft_write_param(param, buffer, i);
}
