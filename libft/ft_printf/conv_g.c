/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_g.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:12:35 by jmichaud          #+#    #+#             */
/*   Updated: 2017/01/26 12:15:49 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

int				conv_upg(va_list ap, t_buffer *buf, t_arg *arg)
{
	return (conv_g(ap, buf, arg));
}

int				conv_g(va_list ap, t_buffer *buf, t_arg *arg)
{
	va_list		ap_cp;
	long double	nb;
	long double	nb_cp;
	int			e;

	if (arg->isprecision == 0 && arg->precision == 0)
		arg->precision = 6;
	arg->isprecision = 1;
	arg->conversion = (arg->conversion == 'g') ? 'e' : 'E';
	va_copy(ap_cp, ap);
	nb = get_double_nb(ap_cp, arg);
	va_end(ap_cp);
	nb_cp = nb;
	e = get_exp(&nb);
	if (e < -4 || e >= arg->precision)
	{
		arg->precision--;
		return (conv_e(ap, buf, arg));
	}
	else
	{
		arg->precision -= ft_ldlen_base(nb_cp, 10);
		return (conv_f(ap, buf, arg));
	}
}
