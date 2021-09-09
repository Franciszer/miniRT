/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:42:43 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/20 14:41:06 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list *lst)
{
	int		i;
	t_list	*nav;

	i = 0;
	nav = lst;
	if (!lst)
		return (0);
	while (nav)
	{
		nav = nav->next;
		i++;
	}
	return (i);
}
