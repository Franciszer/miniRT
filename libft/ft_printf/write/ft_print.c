/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:52:49 by frthierr          #+#    #+#             */
/*   Updated: 2019/11/12 17:57:30 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_print(char c, char *buffer, int *i)
{
	static int w;

	buffer[*i] = c;
	if (++(*i) == BUFF_SIZE)
	{
		w += BUFF_SIZE;
		write(1, buffer, BUFF_SIZE);
		ft_bzero(buffer, BUFF_SIZE);
		*i = 0;
	}
	return (w + *i);
}
