/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:32:56 by frthierr          #+#    #+#             */
/*   Updated: 2019/11/12 14:33:14 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_init_param(t_param *param)
{
	param->flag = 0;
	param->prec = INITPREC;
	param->spec = 0;
	param->width = 0;
	param->value = 0;
}
