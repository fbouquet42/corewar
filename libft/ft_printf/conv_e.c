/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:12:35 by jmichaud          #+#    #+#             */
/*   Updated: 2017/01/27 15:28:28 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

int				conv_upe(va_list ap, t_buffer *buf, t_arg *arg)
{
	arg->len = 'l';
	return (conv_e(ap, buf, arg));
}

void			power_str(char *str, char c, int e)
{
	int			sign;

	sign = (e < 0) ? -1 : 1;
	while (*str)
		str++;
	*(str - 1) = '0' + ((e * sign) % 10);
	*(str - 2) = '0' + ((e * sign) / 10);
	*(str - 3) = (e < 0) ? '-' : '+';
	*(str - 4) = (c == 'e') ? 'e' : 'E';
}

int				get_exp(long double *nb)
{
	int			e;

	e = 0;
	while ((*nb > 0 && *nb < 1) || (*nb < 0 && *nb > -1))
	{
		*nb *= 10;
		e--;
	}
	while (*nb >= 10 || *nb <= -10)
	{
		*nb /= 10;
		e++;
	}
	return (e);
}

void			core_conv_e(t_buffer *buf, t_arg *arg, int len, char *str)
{
	arg->conversion = 'd';
	if (arg->left)
		fill_buf_left(arg, buf, len, str);
	else
		fill_buf_right(arg, buf, len, str);
}

int				conv_e(va_list ap, t_buffer *buf, t_arg *arg)
{
	char		*str;
	int			len;
	long double	nb;
	int			e;

	len = (arg->isprecision == 0) ? 6 : arg->precision;
	len = (arg->isprecision && !arg->precision) ? 3 : len + 4;
	nb = get_double_nb(ap, arg);
	e = get_exp(&nb);
	if (!(str = ft_ldtoa(nb, len, 10)))
		return (-1);
	len = ft_strlen(str);
	arg->precision -= len;
	len += (nb >= 0 && (arg->plus || arg->space)) ? 1 : 0;
	ajust_precision(arg, nb);
	if (nb < 0)
		str++;
	power_str(str, arg->conversion, e);
	core_conv_e(buf, arg, len, str);
	if (nb < 0)
		str--;
	free(str);
	return (0);
}
