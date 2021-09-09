/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:08:58 by frthierr          #+#    #+#             */
/*   Updated: 2020/01/16 14:18:05 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	BUGGED
*/

void			ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*nav;

	if (!alst || !new)
		return ;
	nav = *alst;
	if (!nav)
		nav = new;
	else
	{
		nav = ft_lstlast(nav);
		nav->next = new;
	}
}
