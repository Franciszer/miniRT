/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:35:47 by frthierr          #+#    #+#             */
/*   Updated: 2020/01/14 18:29:28 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *s, ...)
{
	int		i;
	int		j;
	char	buffer[BUFF_SIZE];
	t_param	param;
	va_list	list;

	i = 0;
	j = -1;
	va_start(list, s);
	while (s[++j])
	{
		if (s[j] == '%')
		{
			param = ft_get_param(list, s, &j);
			if (ft_check_param(param))
				ft_print_param(param, buffer, &i);
			else if (param.spec == ERROR)
				ft_only_widprec(param, buffer, &i);
		}
		else
			ft_print(s[j], buffer, &i);
	}
	va_end(list);
	write(1, buffer, i);
	return (ft_print('\0', buffer, &i) - 1);
}
