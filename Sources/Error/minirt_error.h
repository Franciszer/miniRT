/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_error.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:30:07 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/21 21:21:48 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_ERROR_H

# define MINIRT_ERROR_H

# define ERR_INVALID_FILE "Cannot read file\n"
# define ERR_ID_MUCH "There can only be one ID per line\n"
# define ERR_ID_NO "Line has to contain one ID\n"
# define ERR_ID_VALS "Line doesn\'t have the right number of values\n"

# define ERR_RES_MUCH "There can only be one Resolution\n"

# define ERR_NVALS "Wrong number of values\n"
# define ERR_VALS "Wrong value\n"

int	print_error(char *error);

#endif
