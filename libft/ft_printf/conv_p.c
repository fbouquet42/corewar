/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:11:53 by jmichaud          #+#    #+#             */
/*   Updated: 2016/12/28 16:09:24 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

/*
** flags
** managed: -
** undefined behavior: # 0 + ' '
**
** length modifier
** undefined behavior: h hh l ll j z
*/

char			*get_zero_str(int precision)
{
	char		*str;

	if (precision == 0)
		str = ft_strdup("");
	else
	{
		str = ft_strnew(precision);
		if (str)
			str = (char *)ft_memset(str, '0', precision);
	}
	return (str);
}

int				conv_p(va_list ap, t_buffer *buf, t_arg *arg)
{
	char		*str;
	int			len;
	uintmax_t	nb;

	nb = va_arg(ap, uintmax_t);
	if (nb == 0 && arg->isprecision && arg->precision != 1)
		str = get_zero_str(arg->precision);
	else
		str = ft_ullitoa_base(nb, 16);
	if (!str)
		return (-1);
	len = ft_strlen(str) + 2;
	str = ft_strlowcase(str);
	if (arg->isprecision && arg->precision < len)
		arg->zero = 0;
	arg->precision = (arg->precision < len) ? 0 : arg->precision;
	arg->precision -= len - 2;
	arg->precision = (arg->precision < 0) ? 0 : arg->precision;
	if (arg->left)
		fill_buf_left(arg, buf, len, str);
	else
		fill_buf_right(arg, buf, len, str);
	free(str);
	return (0);
}
