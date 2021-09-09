/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:34:33 by frthierr          #+#    #+#             */
/*   Updated: 2019/11/10 20:17:33 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_pstrlen(char *s, long prec)
{
	if (prec == INITPREC || ft_strlen(s) < (size_t)prec)
		return (ft_strlen(s));
	else
		return ((int)prec);
}
