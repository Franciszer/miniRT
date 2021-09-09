/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:01:30 by frthierr          #+#    #+#             */
/*   Updated: 2019/11/13 14:14:49 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_get_width(t_param *param, char *buffer, int *i)
{
	if (buffer[*i] == '*')
	{
		param->width = -1;
		(*i)++;
	}
	else
	{
		while (buffer[*i] && buffer[*i] >= '0' && buffer[*i] <= '9')
		{
			param->width = param->width * 10 + (int)buffer[*i] - '0';
			(*i)++;
		}
	}
}

static void	ft_get_precision(t_param *param, char *buffer, int *i)
{
	if (buffer[*i] && buffer[*i] == '.')
	{
		param->prec = 0;
		(*i)++;
		if (buffer[*i] && buffer[*i] == '*')
		{
			param->prec = -1;
			(*i)++;
		}
		else
		{
			if (buffer[*i] == '-' || buffer[*i] == '+')
			{
				while (buffer[(*i)++] == '-' || buffer[*i] == '+' || \
				(buffer[*i] >= '0' && buffer[*i] <= '9'))
					param->prec = 0;
			}
			while (buffer[*i] >= '0' && buffer[*i] <= '9')
			{
				param->prec = param->prec * 10 + (int)buffer[(*i)++] - '0';
			}
			if (!param->prec && buffer[*i] < '0' && buffer[*i] > '9')
				param->prec = ERROR;
		}
	}
}

static void	ft_get_specififer(t_param *param, char *buffer, int *i)
{
	if (buffer[*i] && ft_is_specifier(buffer[*i]))
	{
		param->spec = (int)buffer[*i];
		(*i)++;
	}
	else
		param->spec = ERROR;
}

static void	ft_get_value(va_list list, t_param *param)
{
	if (param->width == -1)
		param->width = va_arg(list, int);
	if (param->prec == -1)
		param->prec = va_arg(list, int);
	if (param->spec == 'd' || param->spec == 'i')
		param->value = va_arg(list, int);
	else if (param->spec == 'u')
		param->value = (long)va_arg(list, unsigned int);
	else if (param->spec == 'c')
		param->value = (long)va_arg(list, int);
	else if (param->spec == 's')
		param->value = (long)va_arg(list, char *);
	else if (param->spec == 'p')
		param->value = (long)va_arg(list, void *);
	else if (param->spec == 'x')
		param->value = (long)va_arg(list, unsigned long);
	else if (param->spec == 'X')
		param->value = (long)va_arg(list, long);
}

t_param		ft_get_param(va_list list, char *buffer, int *i)
{
	int		j;
	t_param param;

	j = *i + 1;
	ft_init_param(&param);
	ft_get_flags(&param, buffer, &j);
	ft_get_width(&param, buffer, &j);
	if (ft_check_param(param))
		ft_get_precision(&param, buffer, &j);
	if (ft_check_param(param))
		ft_get_specififer(&param, buffer, &j);
	if (ft_check_param(param) && param.spec)
		ft_get_value(list, &param);
	if (ft_check_param(param) && param.width < 0)
	{
		param.width *= -1;
		if (param.flag != '-' && param.flag != '0' + '-')
			param.flag += '-';
	}
	*i = j - 1;
	return (param);
}
