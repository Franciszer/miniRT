/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:10:32 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 19:08:00 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		main(int ac, char **av)
{
	t_obj		*obj;

	if (!is_rtfile(av[1]) || !(obj = parse_rt(av[1])))
		return (0);
	if (ac == 2)
		display_rt(obj);
	else if (ac == 3)
	{
		if (!ft_strncmp(av[2], "--save", ft_strlen("--save")))
		{
			get_inters_rt(obj);
			if (!write_bmp(obj))
				print_error("ERROR WRITING\n");
			else
				ft_printf("SUCCESS!\n");
		}
		else
			print_error("Invalid argument\n");
		free_obj_rt(obj);
	}
	else
		print_error("Wrong number of arguments\n");
	return (0);
}
