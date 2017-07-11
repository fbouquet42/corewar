/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:13:39 by jmichaud          #+#    #+#             */
/*   Updated: 2016/12/29 12:23:29 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			put_0x(t_buffer *buf, t_arg *arg, char c)
{
	if (c != '0' && c != ' ')
	{
		if (arg->sharp && (arg->conversion == 'o' || arg->conversion == 'O'))
			putc_buf('0', buf);
		if (arg->sharp && arg->conversion == 'X')
			puts_buf("0X", buf);
		else if (arg->sharp && arg->conversion == 'x')
			puts_buf("0x", buf);
	}
	if (arg->conversion == 'p')
	{
		arg->conversion = 0;
		puts_buf("0x", buf);
	}
	if (arg->conversion == 'd' && arg->isprecision < 0)
		putc_buf('-', buf);
	else if (arg->conversion == 'd' && arg->plus)
		putc_buf('+', buf);
	else if (arg->conversion == 'd' && arg->space)
		putc_buf(' ', buf);
	arg->conversion = (arg->conversion == 'd') ? 0 : arg->conversion;
}

void			put_string_in_buf(t_arg *arg, t_buffer *buf, char *str)
{
	if (!(*str == ' ' && arg->field == 0 && arg->isprecision
											&& arg->precision == 0))
		puts_buf(str, buf);
}

void			fill_buf_left(t_arg *arg, t_buffer *buf, int len, char *str)
{
	put_0x(buf, arg, *str);
	while (arg->precision > 0 && arg->conversion != 's')
	{
		putc_buf('0', buf);
		arg->precision -= 1;
		arg->field -= 1;
	}
	put_string_in_buf(arg, buf, str);
	while ((arg->field - arg->precision - len) > 0)
	{
		arg->field -= 1;
		putc_buf(' ', buf);
	}
}

void			fill_buf_right(t_arg *arg, t_buffer *buf, int len, char *str)
{
	if (arg->zero && (arg->field - arg->precision - len) > 0)
	{
		put_0x(buf, arg, *str);
		arg->sharp = 0;
	}
	while ((arg->field - arg->precision - len) > 0)
	{
		arg->field -= 1;
		if (arg->zero)
			putc_buf('0', buf);
		else
			putc_buf(' ', buf);
	}
	put_0x(buf, arg, *str);
	while (arg->precision > 0)
	{
		if (arg->zero == 0 && arg->conversion == 's')
			putc_buf(' ', buf);
		else
			putc_buf('0', buf);
		arg->precision -= 1;
		arg->field -= 1;
	}
	put_string_in_buf(arg, buf, str);
}
