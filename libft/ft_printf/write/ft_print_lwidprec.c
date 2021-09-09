/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lwidprec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 10:43:31 by frthierr          #+#    #+#             */
/*   Updated: 2019/11/12 11:16:17 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_print_lwidprec(t_param param, char *buffer, int *i)
{
	int len;

	if (param.value < 0)
	{
		ft_print('-', buffer, i);
		param.value *= -1;
		param.width--;
	}
	len = ft_paramlen(param.value, param.spec);
	while (param.prec > len)
	{
		ft_print('0', buffer, i);
		param.prec--;
		param.width--;
	}
	if (param.spec == 0 && !param.value)
		ft_print(0, buffer, i);
	else
		ft_write_param(param, buffer, i);
	param.width -= len;
	while (param.width > 0)
	{
		ft_print(' ', buffer, i);
		param.width--;
	}
}
