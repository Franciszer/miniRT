/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:33:27 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:41:19 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_inter	**which_inter(t_list *inter_list, int *n)
{
	t_list	*nav;
	int		i;

	i = 0;
	nav = inter_list;
	if (*n < 0)
		*n = ft_lstlen(inter_list) - 1;
	else if (*n > ft_lstlen(inter_list) - 1)
		*n = 0;
	i = 0;
	while (nav->next)
	{
		if (i == *n)
		{
			return ((t_inter**)nav->content);
		}
		nav = nav->next;
		i++;
	}
	return ((t_inter**)nav->content);
}
