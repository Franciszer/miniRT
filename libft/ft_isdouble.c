/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 10:01:30 by frthierr          #+#    #+#             */
/*   Updated: 2020/01/16 14:12:13 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isdouble(char *s)
{
	int ct;
	int	pt;

	ct = 0;
	pt = 0;
	if (*s == '-')
		s++;
	while (ft_isdigit(*s) || *s == '.')
	{
		while (ft_isdigit(*s))
		{
			if (!ct || (pt == 1 && *(s - 1) == '.'))
				ct++;
			s++;
		}
		if (*s == '.')
		{
			pt++;
			s++;
		}
	}
	if ((ct == 1 && !pt) || (ct == 2 && pt == 1))
		return (1);
	else
		return (0);
}
