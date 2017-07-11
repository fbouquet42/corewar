/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:25:04 by jmichaud          #+#    #+#             */
/*   Updated: 2016/12/27 13:35:17 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

int				conv_upu(va_list ap, t_buffer *buf, t_arg *arg)
{
	arg->len = 'l';
	return (conv_u(ap, buf, arg));
}

int				conv_u(va_list ap, t_buffer *buf, t_arg *arg)
{
	char		*str;
	int			len;

	str = ft_ullitoa_base(get_unsigned_nb(ap, arg), 10);
	if (str && arg->thousand)
		str = thousand_separator(str, 3);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	if (*str == '0' && arg->isprecision && !arg->precision)
		str[0] = ' ';
	if ((arg->isprecision && arg->precision == 0)
		|| (arg->isprecision && arg->precision < arg->field))
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
