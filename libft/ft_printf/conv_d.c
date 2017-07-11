/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:12:35 by jmichaud          #+#    #+#             */
/*   Updated: 2017/01/24 14:42:54 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

/*
** flags
** managed: 0 - + ' '
** undefined behavior: #
** tips: flag '0' is ignored when flag '-' is present
**
** length modifier
** h: short
** hh: char
** l: long
** ll: long long
** j: intmax_t (aka 'long')
** z: size_t (aka 'unsigned long')
*/

int				conv_i(va_list ap, t_buffer *buf, t_arg *arg)
{
	arg->conversion = 'd';
	return (conv_d(ap, buf, arg));
}

int				conv_upd(va_list ap, t_buffer *buf, t_arg *arg)
{
	arg->len = 'l';
	arg->conversion = 'd';
	return (conv_d(ap, buf, arg));
}

intmax_t		get_signed_nb(va_list ap, t_arg *arg)
{
	if (arg->len == 'h')
		return ((short)va_arg(ap, int));
	else if (arg->len == 'H')
		return ((char)va_arg(ap, int));
	else if (arg->len == 'l')
		return (va_arg(ap, long int));
	else if (arg->len == 'I')
		return (va_arg(ap, long long int));
	else if (arg->len == 'j')
		return (va_arg(ap, intmax_t));
	else if (arg->len == 'z')
		return (va_arg(ap, size_t));
	else
		return (va_arg(ap, int));
}

int				get_len_and_precision(t_arg *arg, char *str, intmax_t nb)
{
	int			len;

	if (str[0] == '0' && arg->isprecision && arg->precision == 0)
		str[0] = ' ';
	if ((arg->isprecision && arg->precision == 0)
		|| (arg->isprecision && arg->precision < arg->field))
		arg->zero = 0;
	len = ft_strlen(str);
	arg->precision -= len;
	len += (nb >= 0 && (arg->plus || arg->space)) ? 1 : 0;
	arg->precision += (nb < 0) ? 1 : 0;
	arg->precision = (arg->precision < 0) ? 0 : arg->precision;
	arg->isprecision = (nb < 0) ? -1 : arg->isprecision;
	return (len);
}

int				conv_d(va_list ap, t_buffer *buf, t_arg *arg)
{
	char		*str;
	int			len;
	intmax_t	nb;

	nb = get_signed_nb(ap, arg);
	if (nb == 0 && arg->isprecision && arg->precision != 1)
		str = get_zero_str(arg->precision);
	else
		str = ft_intmaxtoa_base(nb, 10);
	if (str && arg->thousand)
		str = thousand_separator(str, 3);
	if (!str)
		return (-1);
	len = get_len_and_precision(arg, str, nb);
	if (nb < 0)
		str++;
	if (arg->left)
		fill_buf_left(arg, buf, len, str);
	else
		fill_buf_right(arg, buf, len, str);
	if (nb < 0)
		str--;
	free(str);
	return (0);
}
