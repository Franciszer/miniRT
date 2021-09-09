/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:34:52 by frthierr          #+#    #+#             */
/*   Updated: 2019/11/12 15:29:27 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_write_param(t_param param, char *buffer, int *i)
{
	if (param.width == -1)
		param.width = param.value;
	if (param.prec == -1)
		param.prec = param.value;
	if (param.prec == 0 && !param.value)
		return ;
	else if (param.spec == 'd' || param.spec == 'i')
		ft_write_int(param.value, buffer, i);
	else if (param.spec == 'u')
		ft_write_uint((unsigned int)param.value, buffer, i);
	else if (param.spec == 'c')
		ft_print((char)param.value, buffer, i);
	else if (param.spec == 's')
		ft_write_str((char *)param.value, buffer, i);
	else if (param.spec == 'p')
		ft_write_memory((void *)param.value, buffer, i);
	else if (param.spec == 'x')
		ft_write_hex((unsigned int)param.value, buffer, i, HEX_LOWER);
	else if (param.spec == 'X')
		ft_write_hex((unsigned int)param.value, buffer, i, HEX_UPPER);
	else if (param.spec == '%')
		ft_print('%', buffer, i);
}
