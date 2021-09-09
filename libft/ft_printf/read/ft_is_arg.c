/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:47:26 by frthierr          #+#    #+#             */
/*   Updated: 2019/10/29 18:55:54 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_is_arg(char *buffer, int *i)
{
	int j;

	*i += 1;
	j = *i;
	while (j < BUFF_SIZE)
	{
		if (ft_is_specifier(buffer[j]))
			return (1);
		j++;
	}
	return (0);
}
