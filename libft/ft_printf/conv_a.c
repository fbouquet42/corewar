/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:12:35 by jmichaud          #+#    #+#             */
/*   Updated: 2017/02/01 15:44:01 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

void			round_str(char *str)
{
	str--;
	while (*str == 'f')
	{
		*str-- = '0';
		if (*str == '.')
			str--;
	}
	if (*str == '9')
		*str = 'a';
	else
		*str += 1;
}

void			fill_str_hexa(char *str, long double nb)
{
	const char	tab[] = "0123456789abcdef";

	if (nb < 0)
	{
		nb *= -1;
		*str++ = '-';
	}
	*str++ = '0';
	*str++ = 'x';
	*str++ = '1';
	*str++ = '.';
	nb -= (char)nb;
	while (*str)
	{
		nb *= 16;
		*str++ = tab[(unsigned char)nb];
		nb -= (char)nb;
	}
}

void			power_str_hexa(char *str, char c, int e)
{
	int			sign;

	sign = (e < 0) ? -1 : 1;
	while (*str)
		str++;
	str--;
	while (e > 9 || e < -9)
	{
		*str-- = '0' + (e * sign % 10);
		e /= 10;
	}
	*str-- = '0' + (e * sign % 10);
	*str-- = (sign == -1) ? '-' : '+';
	if (*str > '8')
		round_str(str);
	*str-- = (c == 'a') ? 'p' : 'P';
}

int				get_a_len(int e, t_arg *arg, long double nb)
{
	int			len;
	int			dblen;

	len = (e > 99 || e < -99) ? 4 + 5 : 4 + 4;
	len -= ((e > 0 && e < 10) || (e < 0 && e > -10)) ? 1 : 0;
	len += (nb < 0) ? 1 : 0;
	dblen = 0;
	while (nb != 0)
	{
		nb *= 16;
		nb -= (char)nb;
		dblen++;
	}
	if (dblen > 13)
		dblen = 13;
	len += (arg->isprecision == 0) ? dblen : arg->precision;
	len -= (arg->isprecision && !arg->precision) ? 1 : 0;
	return (len);
}

int				conv_a(va_list ap, t_buffer *buf, t_arg *arg)
{
	char		*str;
	int			len;
	long double	nb;
	int			e;

	nb = get_double_nb(ap, arg);
	e = get_exp_base(&nb, 2);
	len = get_a_len(e, arg, nb);
	if (!(str = ft_strnew(len)))
		return (-1);
	ft_memset(str, 'a', len);
	fill_str_hexa(str, nb);
	arg->precision -= len;
	len += (nb >= 0 && (arg->plus || arg->space)) ? 1 : 0;
	ajust_precision(arg, nb);
	if (nb < 0)
		str++;
	power_str_hexa(str, arg->conversion, e);
	if (arg->conversion == 'A')
		ft_strupcase(str);
	core_conv_e(buf, arg, len, str);
	if (nb < 0)
		str--;
	free(str);
	return (0);
}
