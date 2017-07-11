/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:12:35 by jmichaud          #+#    #+#             */
/*   Updated: 2017/01/25 14:36:37 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

int				conv_upf(va_list ap, t_buffer *buf, t_arg *arg)
{
	arg->len = 'l';
	arg->conversion = 'f';
	return (conv_f(ap, buf, arg));
}

void			ajust_precision(t_arg *arg, double nb)
{
	arg->precision += (nb < 0) ? 1 : 0;
	arg->precision = (arg->precision < 0) ? 0 : arg->precision;
	arg->isprecision = (nb < 0) ? -1 : arg->isprecision;
}

long double		get_double_nb(va_list ap, t_arg *arg)
{
	if (arg->len == 'L')
		return (va_arg(ap, long double));
	else
		return (va_arg(ap, double));
}

int				conv_f(va_list ap, t_buffer *buf, t_arg *arg)
{
	char			*str;
	int				len;
	long double		nb;

	arg->conversion = 'd';
	len = (arg->isprecision == 0) ? 6 : arg->precision;
	len = (!arg->sharp && arg->isprecision && !arg->precision) ? -1 : len;
	nb = get_double_nb(ap, arg);
	if (!(str = ft_ldtoa(nb, len, 10)))
		return (-1);
	len = ft_strlen(str);
	arg->precision -= len;
	len += (nb >= 0 && (arg->plus || arg->space)) ? 1 : 0;
	ajust_precision(arg, nb);
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
