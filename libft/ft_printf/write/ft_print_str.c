/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 11:12:41 by frthierr          #+#    #+#             */
/*   Updated: 2019/11/12 14:27:13 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_str(char *s, t_param param, char *buffer, int *i)
{
	int	len;
	int ilen;
	int	j;

	len = ft_pstrlen(s, param.prec);
	ilen = len;
	j = 0;
	while (param.width > len && (param.flag != '-' && param.flag != '-' + '0'))
	{
		if (param.flag >= '0')
			ft_print('0', buffer, i);
		else
			ft_print(' ', buffer, i);
		param.width--;
	}
	while (s[j] && len)
	{
		ft_print(s[j], buffer, i);
		j++;
		len--;
	}
	while (param.width-- > ilen)
		ft_print(' ', buffer, i);
}
