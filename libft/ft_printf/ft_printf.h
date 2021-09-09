/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:00:22 by frthierr          #+#    #+#             */
/*   Updated: 2019/11/15 10:04:40 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <stdio.h>
# include "libft/libft.h"
# define BUFF_SIZE 4096
# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"
# define INITPREC -10000
# define ERROR	-222222

typedef	struct	s_param
{
	long int	value;
	int			spec;
	int			width;
	int			prec;
	int			flag;
}				t_param;

int				ft_printf(char *s, ...);
int				ft_is_specifier(char c);
int				ft_is_flag(char c);
int				ft_print(char c, char *buffer, int *i);
int				ft_is_arg(char *buffer, int *i);
void			ft_init_param(t_param *param);
t_param			ft_get_param(va_list list, char *buffer, int *i);
void			ft_write_int(long int d, char *buffer, int *i);
void			ft_write_uint(unsigned int d, char *buffer, int *i);
void			ft_write_str(char *s, char *buffer, int *i);
void			ft_write_hex(unsigned long d, char *buffer, int *i, char *base);
void			ft_write_memory(void *p, char *buffer, int *i);
void			ft_write_param(t_param param, char *buffer, int *i);
void			ft_print_param(t_param param, char *buffer, int *i);
int				ft_paramlen(long value, char spec);
void			ft_print_widprec(t_param param, int len, char *buffer, int *i);
void			ft_print_lwidprec(t_param param, char *buffer, int *i);
void			ft_print_str(char *s, t_param param, char *buffer, int *i);
void			ft_print_memory(t_param param, int len, char *buffer, int *i);
int				ft_pstrlen(char *s, long prec);
void			ft_print_char(t_param param, int len, char *buffer, int *i);
int				ft_check_param(t_param param);
void			ft_only_widprec(t_param param, char *buffer, int *i);
void			ft_write_percentage(t_param param, char *buffer, int *i);
void			ft_print_hex(t_param param, int len, char *buffer, int *i);
void			ft_init_param(t_param *param);
void			ft_get_flags(t_param *param, char *buffer, int *i);

#endif
