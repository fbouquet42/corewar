/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:29:50 by jmichaud          #+#    #+#             */
/*   Updated: 2017/01/23 19:10:49 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int				fill_char_buff_left(t_arg *arg, t_buffer *buf, wchar_t c)
{
	int			ret;

	ret = putint_buf(c, buf);
	arg->field -= ft_wcharlen(c);
	while (arg->field > 0)
	{
		putc_buf(' ', buf);
		arg->field -= 1;
	}
	return (ret);
}

int				fill_char_buff_right(t_arg *arg, t_buffer *buf, wchar_t c)
{
	int			len;
	int			ret;

	len = ft_wcharlen(c);
	while (arg->field - len > 0)
	{
		if (arg->zero)
			putc_buf('0', buf);
		else
			putc_buf(' ', buf);
		arg->field -= 1;
	}
	ret = putint_buf(c, buf);
	return (ret);
}

int				conv_upc(va_list ap, t_buffer *buf, t_arg *arg)
{
	wchar_t		c;

	c = va_arg(ap, wchar_t);
	if (arg->left)
		return (fill_char_buff_left(arg, buf, c));
	else
		return (fill_char_buff_right(arg, buf, c));
}

int				conv_c(va_list ap, t_buffer *buf, t_arg *arg)
{
	char		c;

	if (arg->len == 'l')
		return (conv_upc(ap, buf, arg));
	c = (char)va_arg(ap, int);
	if (arg->left)
		return (fill_char_buff_left(arg, buf, c));
	else
		return (fill_char_buff_right(arg, buf, c));
}
