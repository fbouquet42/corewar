/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:39:03 by jmichaud          #+#    #+#             */
/*   Updated: 2017/01/26 16:08:55 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"
#include "libft.h"

int				adjust_len(char *str)
{
	int			len;

	len = 0;
	while (*str)
	{
		if (ft_iscntrl(*str) == 1)
			len += ft_nblen_base(*str, 10);
		str++;
	}
	return (len);
}

void			get_nonprinting_char(char *str, char *start)
{
	int			len;
	int			power;

	while (*start)
	{
		if (ft_iscntrl(*start) == 1)
		{
			*str++ = '\\';
			power = 1;
			len = ft_nblen_base(*start, 10);
			while (--len > 0)
				power *= 10;
			while (power >= 1)
			{
				*str++ = *start / power % 10 + '0';
				power /= 10;
			}
		}
		else
			*str++ = *start;
		start++;
	}
}

void			put_nonprintable_char(char *str, char c)
{
	int			len;
	int			power;

	*str++ = '\\';
	len = ft_nblen_base(c, 10);
	power = 1;
	while (--len > 0)
		power *= 10;
	while (power >= 1)
	{
		*str++ = c / power % 10 + '0';
		power /= 10;
	}
}

int				conv_upr(va_list ap, t_buffer *buf, t_arg *arg)
{
	char		c;
	char		*str;
	int			len;

	c = (char)va_arg(ap, int);
	if (ft_iscntrl(c) == 1)
	{
		len = ft_nblen_base(c, 10) + 1;
		if (!(str = ft_strnew(len)))
			return (-1);
		put_nonprintable_char(str, c);
		if (arg->left)
			fill_buf_left(arg, buf, len, str);
		else
			fill_buf_right(arg, buf, len, str);
		free(str);
	}
	else
	{
		if (arg->left)
			return (fill_char_buff_left(arg, buf, c));
		else
			return (fill_char_buff_right(arg, buf, c));
	}
	return (0);
}

int				conv_r(va_list ap, t_buffer *buf, t_arg *arg)
{
	char		*start;
	char		*str;
	int			len;

	start = va_arg(ap, char *);
	len = ft_strlen(start);
	len += adjust_len(start);
	if (!(str = ft_strnew(len)))
		return (-1);
	get_nonprinting_char(str, start);
	if (arg->zero && arg->isprecision)
		arg->zero = 0;
	arg->precision -= len;
	arg->precision = (arg->precision < 0) ? 0 : arg->precision;
	if (arg->left)
		fill_buf_left(arg, buf, len, str);
	else
		fill_buf_right(arg, buf, len, str);
	free(str);
	return (0);
}
