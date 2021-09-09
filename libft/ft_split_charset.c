/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:24:28 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:37:45 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int			ft_is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int			count_words(char *s, char *charset)
{
	int count;

	count = 0;
	while (*s)
	{
		while (*s && ft_is_charset(*s, charset))
			s++;
		if (*s && !ft_is_charset(*s, charset))
		{
			count++;
			while (*s && !ft_is_charset(*s, charset))
				s++;
		}
	}
	return (count);
}

static char			*ft_malloc_tab(char *s, char *charset)
{
	char	*tab;
	int		i;

	i = 0;
	while (s[i] && !(ft_is_charset(s[i], charset)))
		i++;
	if (!(tab = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] && !(ft_is_charset(s[i], charset)))
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static void			**free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return ((void**)0);
}

char				**ft_split_charset(char const *s, char *charset)
{
	char	**tab;
	char	*str;
	int		i;

	str = (char *)s;
	if (!(tab = (char **)malloc(sizeof(char*) *\
		(count_words(str, charset) + 1))))
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && (ft_is_charset(*str, charset)))
			str++;
		if (*str && !(ft_is_charset(*str, charset)))
		{
			if (!(tab[i++] = ft_malloc_tab(str, charset)))
				return ((char**)free_tab(tab));
			while (*str && !(ft_is_charset(*str, charset)))
				str++;
		}
	}
	tab[i] = 0;
	return (tab);
}
