/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:00:28 by jmichaud          #+#    #+#             */
/*   Updated: 2017/01/27 14:56:44 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void			get_flag(char **format, t_arg *arg)
{
	while (ft_isflag(**format))
	{
		if (**format == '#')
			arg->sharp = 1;
		else if (**format == '0')
			arg->zero = 1;
		else if (**format == '-')
			arg->left = 1;
		else if (**format == '+')
			arg->plus = 1;
		else if (**format == ' ')
			arg->space = 1;
		else if (**format == '\'')
			arg->thousand = 1;
		*format += 1;
	}
}

void			check_wildcard(char **format, t_arg *arg, va_list ap, char c)
{
	int			nb;

	nb = 0;
	if (**format == '*')
	{
		nb = va_arg(ap, int);
		if (nb < 0)
		{
			arg->isprecision = 0;
			c = (c == 'p') ? 0 : c;
			arg->left = (arg->zero == 1) ? 0 : 1;
			nb = (nb == -2147483648) ? -(nb + 1) : -nb;
		}
		*format += 1;
	}
	else if (**format >= '0' && **format <= '9')
	{
		nb = ft_atoi(*format);
		while (ft_isdigit(**format))
			*format += 1;
	}
	if (c == 'f')
		arg->field = nb;
	else if (c == 'p')
		arg->precision = nb;
}

void			get_field_and_precision(char **format, t_arg *arg, va_list ap)
{
	while (**format == '*' || (**format >= '0' && **format <= '9'))
		check_wildcard(format, arg, ap, 'f');
	get_flag(format, arg);
	if (**format == '.')
	{
		*format += 1;
		arg->isprecision = 1;
		check_wildcard(format, arg, ap, 'p');
		while (ft_isdigit(**format) || **format == '.')
			*format += 1;
	}
	else if (**format == '*' || (**format >= '1' && **format <= '9'))
		get_field_and_precision(format, arg, ap);
	get_flag(format, arg);
}

void			get_len(char **format, t_arg *arg)
{
	if (**format == 'h')
	{
		*format += 1;
		if (**format == 'h')
			arg->len = 'H';
		else
			arg->len = 'h';
	}
	else if (**format == 'l')
	{
		*format += 1;
		if (**format == 'l')
			arg->len = 'I';
		else
			arg->len = 'l';
	}
	else if (**format == 'j' || **format == 'z' || **format == 'L')
	{
		arg->len = **format;
		*format += 1;
	}
	*format += (arg->len == 'I' || arg->len == 'H') ? 1 : 0;
	if (**format == 'l')
		get_len(format, arg);
	get_flag(format, arg);
}

void			fill_arg(char **format, va_list ap, t_arg *arg)
{
	const char	*str = "%sSpdDioOuUxXcCfFbneEgGrRkKaA";

	get_dollar(format, arg);
	get_flag(format, arg);
	get_field_and_precision(format, arg, ap);
	get_len(format, arg);
	while (**format &&
			(ft_isflag(**format)
			|| ft_islen(**format)
			|| ft_isprecision(**format)))
		*format += 1;
	if (ft_isconversion(**format))
	{
		arg->conversion = **format;
		arg->fnum = ft_strchr(str, **format) - str;
	}
}
