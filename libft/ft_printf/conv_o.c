/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:23:33 by jmichaud          #+#    #+#             */
/*   Updated: 2016/12/27 12:33:31 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

int				conv_upo(va_list ap, t_buffer *buf, t_arg *arg)
{
	arg->len = 'l';
	return (conv_o(ap, buf, arg));
}

int				conv_o(va_list ap, t_buffer *buf, t_arg *arg)
{
	char		*str;
	int			len;

	if (!(str = ft_ullitoa_base(get_unsigned_nb(ap, arg), 8)))
		return (-1);
	len = ft_strlen(str);
	if (*str == '0' && arg->isprecision && !arg->precision && !arg->sharp)
		str[0] = ' ';
	if ((arg->isprecision && arg->precision == 0)
		|| (arg->isprecision && arg->precision < arg->field))
		arg->zero = 0;
	len += (arg->sharp == 1 && *str != '0' && *str != ' ') ? 1 : 0;
	arg->precision -= len;
	arg->precision = (arg->precision < 0) ? 0 : arg->precision;
	if (arg->left)
		fill_buf_left(arg, buf, len, str);
	else
		fill_buf_right(arg, buf, len, str);
	free(str);
	return (0);
}
