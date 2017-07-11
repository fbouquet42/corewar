/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_k.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:39:03 by jmichaud          #+#    #+#             */
/*   Updated: 2017/01/26 14:39:37 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"
#include "libft.h"

void			put_date(char *str, int date, char c)
{
	int			len;

	while (*str)
		str++;
	len = ft_nblen_base(date, 10);
	str[len] = c;
	while (--len >= 0)
	{
		str[len] = date % 10 + '0';
		date /= 10;
	}
}

char			*get_str_date(va_list ap, int *len, char c)
{
	int			y;
	int			m;
	int			d;
	char		*str;

	y = va_arg(ap, int);
	m = va_arg(ap, int);
	d = va_arg(ap, int);
	*len = ft_nblen_base(y, 10) + ft_nblen_base(m, 10) + ft_nblen_base(d, 10);
	*len += 2;
	if (!(str = ft_strnew(*len)))
		return (NULL);
	put_date(str, y, c);
	put_date(str, m, c);
	put_date(str, d, '\0');
	return (str);
}

int				conv_upk(va_list ap, t_buffer *buf, t_arg *arg)
{
	return (conv_k(ap, buf, arg));
}

int				conv_k(va_list ap, t_buffer *buf, t_arg *arg)
{
	int			len;
	char		*str;

	arg->len = (arg->conversion == 'k') ? '/' : '-';
	if (!(str = get_str_date(ap, &len, arg->len)))
		return (-1);
	arg->precision -= len;
	arg->precision = (arg->precision < 0) ? 0 : arg->precision;
	if (arg->zero && arg->isprecision)
		arg->zero = 0;
	if (arg->left)
		fill_buf_left(arg, buf, len, str);
	else
		fill_buf_right(arg, buf, len, str);
	free(str);
	return (0);
}
