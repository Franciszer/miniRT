/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:27:21 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:40:32 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		print_error(char *error)
{
	char	*message;

	message = ft_strjoin("Error: ", error);
	if (error[0])
		ft_putstr_fd(message, 2);
	free(message);
	return (0);
}
