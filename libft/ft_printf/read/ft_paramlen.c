/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paramlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:27:03 by frthierr          #+#    #+#             */
/*   Updated: 2019/11/12 14:30:02 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_hexlen(long value)
{
	int i;

	i = 0;
	if (!value)
		return (1);
	while (value != 0)
	{
		value /= 16;
		i++;
	}
	return (i);
}

static int	ft_intlen(long value)
{
	int i;

	i = 0;
	if (!value)
		return (1);
	while (value != 0)
	{
		value /= 10;
		i++;
	}
	return (i);
}

int			ft_paramlen(long value, char spec)
{
	int len;

	len = 0;
	if (spec == 'd' || spec == 'i')
		len = ft_intlen(value);
	else if (spec == 'u')
		len = ft_intlen(value);
	else if (spec == 'c')
		len = 1;
	else if (spec == 's')
		len = ft_strlen((char *)value);
	else if (spec == 'p')
		len = ft_hexlen(value);
	else if (spec == 'x')
		len = ft_hexlen(value);
	else if (spec == 'X')
		len = ft_hexlen(value);
	else if (spec == '%')
		len = 1;
	return (len);
}
