/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_percentage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:34:12 by frthierr          #+#    #+#             */
/*   Updated: 2019/11/11 17:43:23 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_write_percentage(t_param param, char *buffer, int *i)
{
	while ((param.flag != '-' || param.flag != '0' + '-') && param.width > 1)
	{
		if (param.flag == '0')
			ft_print('0', buffer, i);
		else
			ft_print(' ', buffer, i);
		param.width--;
	}
	ft_print('%', buffer, i);
	while ((param.flag == '-' || param.flag == '0' + '-') && param.width > 1)
	{
		if (param.flag == '0')
			ft_print('0', buffer, i);
		else
			ft_print(' ', buffer, i);
		param.width--;
	}
}
