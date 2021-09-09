/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:29:20 by frthierr          #+#    #+#             */
/*   Updated: 2019/10/21 18:22:13 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;
	t_list	*nav;

	if (!lst || !f)
		return (NULL);
	if (!(l = ft_lstnew(f(lst->content))))
		return (NULL);
	nav = l;
	while (lst->next)
	{
		lst = lst->next;
		if (!(nav->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&l, del);
			return (NULL);
		}
		nav = nav->next;
	}
	return (l);
}
