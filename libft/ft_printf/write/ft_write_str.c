/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:00:24 by frthierr          #+#    #+#             */
/*   Updated: 2019/10/30 16:12:25 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_write_str(char *s, char *buffer, int *i)
{
	int	j;

	j = 0;
	while (s[j])
	{
		ft_print(s[j], buffer, i);
		j++;
	}
}
