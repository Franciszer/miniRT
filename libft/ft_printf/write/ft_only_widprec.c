/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_widprec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:05:21 by frthierr          #+#    #+#             */
/*   Updated: 2019/11/11 17:23:15 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_only_widprec(t_param param, char *buffer, int *i)
{
	while (param.width > 1)
	{
		if ((param.flag == '0' || param.flag == '0' + '-'))
			ft_print('0', buffer, i);
		else
			ft_print(' ', buffer, i);
		param.width--;
	}
}
