/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:06:53 by frthierr          #+#    #+#             */
/*   Updated: 2020/01/20 14:09:55 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

double	ft_atof(char *s)
{
	double d;
	double power;
	double dec;
	double sign;

	d = 0;
	power = 0;
	dec = 0;
	sign = 1;
	if (*s == '-' && s++)
		sign = -1;
	while (ft_isdigit(*s))
		d = d * 10 + *s++ - '0';
	if (*s == '.')
	{
		s++;
		while (ft_isdigit(*s))
		{
			dec = dec * 10 + *s++ - '0';
			power++;
		}
	}
	d += dec / pow(10, power);
	return (d * sign);
}
