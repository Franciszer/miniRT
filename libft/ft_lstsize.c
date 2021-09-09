/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:50:51 by frthierr          #+#    #+#             */
/*   Updated: 2019/10/15 19:48:26 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	t_list		*nav;
	int			i;

	i = 0;
	nav = lst;
	while (nav)
	{
		nav = nav->next;
		i++;
	}
	return (i);
}
