/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:26:17 by jmichaud          #+#    #+#             */
/*   Updated: 2016/12/28 18:38:20 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"
#include "libft.h"

int				conv_b(va_list ap, t_buffer *buf, t_arg *arg)
{
	char		*str;
	int			len;

	str = ft_ullitoa_base(get_unsigned_nb(ap, arg), 2);
	if (str && arg->thousand)
		str = thousand_separator(str, 4);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	if (*str == '0' && arg->isprecision && arg->precision == 0)
		str[0] = ' ';
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
