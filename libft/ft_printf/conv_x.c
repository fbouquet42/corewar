/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:26:17 by jmichaud          #+#    #+#             */
/*   Updated: 2017/01/24 14:44:31 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"
#include "libft.h"

/*
** flags
** managed: - # 0
** undefined behavior: + ' '
** tips: flag '0' is ignored when flag '-' is present
**
** length modifier
** h: unsigned short
** hh: unsigned char
** l: unsigned long
** ll: unsigned long long
** j: uintmax_t (aka 'unsigned long')
** z: size_t (aka 'unsigned long')
*/

int				conv_upx(va_list ap, t_buffer *buf, t_arg *arg)
{
	return (conv_x(ap, buf, arg));
}

uintmax_t		get_unsigned_nb(va_list ap, t_arg *arg)
{
	if (arg->len == 'h')
		return ((unsigned short)va_arg(ap, unsigned int));
	else if (arg->len == 'H')
		return ((unsigned char)va_arg(ap, unsigned int));
	else if (arg->len == 'l')
		return (va_arg(ap, unsigned long int));
	else if (arg->len == 'I')
		return (va_arg(ap, unsigned long long int));
	else if (arg->len == 'j')
		return (va_arg(ap, uintmax_t));
	else if (arg->len == 'z')
		return (va_arg(ap, size_t));
	else
		return (va_arg(ap, unsigned int));
}

int				conv_x(va_list ap, t_buffer *buf, t_arg *arg)
{
	char		*str;
	int			len;

	if (!(str = ft_ullitoa_base(get_unsigned_nb(ap, arg), 16)))
		return (-1);
	len = ft_strlen(str);
	if (*str == '0' && arg->isprecision && arg->precision == 0)
		str[0] = ' ';
	else if (arg->conversion == 'x')
		str = ft_strlowcase(str);
	if (arg->zero && arg->isprecision)
		arg->zero = 0;
	arg->precision -= len;
	len += (arg->sharp == 1 && *str != '0' && *str != ' ') ? 2 : 0;
	arg->precision = (arg->precision < 0) ? 0 : arg->precision;
	if (arg->left)
		fill_buf_left(arg, buf, len, str);
	else
		fill_buf_right(arg, buf, len, str);
	free(str);
	return (0);
}
