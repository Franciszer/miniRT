/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:27:46 by frthierr          #+#    #+#             */
/*   Updated: 2019/11/12 14:26:59 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		ft_rprint_char(t_param param, int len, char *buffer, int *i)
{
	while (param.width > len)
	{
		if (param.flag == '0')
			ft_print('0', buffer, i);
		else
			ft_print(' ', buffer, i);
		param.width--;
	}
	ft_print((char)param.value, buffer, i);
}

static void		ft_lprint_char(t_param param, int len, char *buffer, int *i)
{
	ft_print((char)param.value, buffer, i);
	while (param.width > len)
	{
		ft_print(' ', buffer, i);
		param.width--;
	}
}

void			ft_print_char(t_param param, int len, char *buffer, int *i)
{
	if (param.flag == '-' || param.flag == '-' + '0')
	{
		ft_lprint_char(param, len, buffer, i);
	}
	else
		ft_rprint_char(param, len, buffer, i);
}
