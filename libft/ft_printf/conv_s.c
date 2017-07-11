/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:38:36 by jmichaud          #+#    #+#             */
/*   Updated: 2017/01/23 19:11:14 by jmichaud         ###   ########.fr       */
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
** managed: l
** undefined behavior: h hh ll j z
*/

void	fill_buf_left_wct(t_arg *arg, t_buffer *buf, int len, wchar_t *wstr)
{
	int		wclen;

	while (len > 0)
	{
		wclen = 1;
		if (*wstr && (arg->isprecision == 0 || arg->precision > 0))
		{
			wclen = ft_wcharlen(*wstr);
			arg->precision -= wclen;
			if ((arg->isprecision && arg->precision >= 0) || !arg->isprecision)
				putint_buf(*wstr, buf);
			else
				wclen = 0;
			arg->field -= wclen;
			wstr += 1;
		}
		else if (!arg->left && arg->zero)
			putc_buf('0', buf);
		else if (arg->field > 0)
			putc_buf(' ', buf);
		len -= wclen;
	}
}

void	fill_buf_right_wct(t_arg *arg, t_buffer *buf, int len, wchar_t *wstr)
{
	int		slen;
	int		i;

	slen = ft_wstrlen(wstr);
	if (arg->isprecision && arg->precision <= slen)
	{
		slen = 0;
		i = 0;
		while (slen + ft_wcharlen(wstr[i]) <= arg->precision)
			slen += ft_wcharlen(wstr[i++]);
	}
	while (len - slen > 0)
	{
		if (arg->zero)
			putc_buf('0', buf);
		else
			putc_buf(' ', buf);
		len -= 1;
		arg->field -= 1;
	}
	fill_buf_left_wct(arg, buf, len, wstr);
}

int		conv_ups(va_list ap, t_buffer *buf, t_arg *arg)
{
	wchar_t		*wstr;
	int			len;
	int			i;

	wstr = va_arg(ap, wchar_t *);
	if (wstr == NULL || (arg->isprecision && arg->precision == 0))
	{
		arg->conversion = 'S';
		return (conv_s(ap, buf, arg));
	}
	len = ft_wstrlen(wstr);
	if (arg->isprecision && len > arg->precision)
	{
		len = 0;
		i = 0;
		while (len + ft_wcharlen(wstr[i]) <= arg->precision)
			len += ft_wcharlen(wstr[i++]);
	}
	if (len < arg->field)
		len = arg->field;
	if (arg->left)
		fill_buf_left_wct(arg, buf, len, wstr);
	else
		fill_buf_right_wct(arg, buf, len, wstr);
	return (0);
}

char	*check_str(t_arg *arg, char *str)
{
	char		*tmp;

	if (str == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	if (str == NULL)
		return (NULL);
	if (arg->isprecision && arg->precision == 0)
	{
		tmp = str;
		str = ft_strdup("");
		free(tmp);
	}
	else if (arg->isprecision && arg->precision < (int)ft_strlen(str))
	{
		tmp = str;
		str = ft_strsub(str, 0, arg->precision);
		free(tmp);
	}
	if (str == NULL)
		return (NULL);
	return (str);
}

int		conv_s(va_list ap, t_buffer *buf, t_arg *arg)
{
	char		*str;
	int			len;

	if (arg->conversion == 's' && arg->len == 'l')
		return (conv_ups(ap, buf, arg));
	if (arg->conversion == 'S')
	{
		arg->conversion = 's';
		str = NULL;
	}
	else
		str = va_arg(ap, char *);
	str = check_str(arg, str);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	arg->precision = 0;
	if (arg->left)
		fill_buf_left(arg, buf, len, str);
	else
		fill_buf_right(arg, buf, len, str);
	free(str);
	return (0);
}
