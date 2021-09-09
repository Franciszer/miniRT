/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:55:27 by frthierr          #+#    #+#             */
/*   Updated: 2019/11/13 14:15:04 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_get_flags(t_param *param, char *buffer, int *i)
{
	while (ft_is_flag(buffer[*i]))
	{
		if (buffer[*i] == '-' && param->flag != '-' && param->flag != '-' + '0')
			param->flag += '-';
		if (buffer[*i] == '0' && param->flag != '0' && param->flag != '-' + '0')
			param->flag += '0';
		(*i)++;
	}
}
