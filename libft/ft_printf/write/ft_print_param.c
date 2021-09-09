/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:21:54 by frthierr          #+#    #+#             */
/*   Updated: 2019/11/12 14:20:47 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_param(t_param param, char *buffer, int *i)
{
	int		len;

	len = ft_paramlen(param.value, param.spec);
	if (param.spec == 's')
	{
		if (!(char *)param.value)
			ft_print_str("(null)", param, buffer, i);
		else
			ft_print_str((char *)param.value, param, buffer, i);
	}
	else if (param.spec == 'p')
		ft_print_memory(param, len, buffer, i);
	else if (param.spec == 'c')
		ft_print_char(param, len, buffer, i);
	else if (param.spec == '%')
		ft_write_percentage(param, buffer, i);
	else if (param.spec == 'x' || param.spec == 'X')
		ft_print_hex(param, len, buffer, i);
	else
	{
		if (param.flag == '-' || param.flag == '-' + '0')
			ft_print_lwidprec(param, buffer, i);
		else
			ft_print_widprec(param, len, buffer, i);
	}
}
