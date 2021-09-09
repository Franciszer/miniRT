/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:13:13 by frthierr          #+#    #+#             */
/*   Updated: 2019/11/12 14:31:17 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_check_param(t_param param)
{
	if (param.flag == ERROR)
		return (0);
	if (param.prec == ERROR)
		return (0);
	if (param.width == ERROR)
		return (0);
	if (param.spec == ERROR)
		return (0);
	return (1);
}
