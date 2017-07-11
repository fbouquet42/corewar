/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 10:53:12 by jmichaud          #+#    #+#             */
/*   Updated: 2017/01/24 14:18:31 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

void			ft_putnbstr(char *str, intmax_t value, int len, char base)
{
	const char		*tab = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int				sign;

	str[0] = '-';
	if (value < 0)
		sign = -1;
	else
		sign = 1;
	while (value >= base || value <= -base)
	{
		str[--len] = tab[value % base * sign];
		value /= base;
	}
	str[--len] = tab[value % base * sign];
}

void			ajust_decimal(char **str)
{
	int			i;
	char		*nstr;

	i = ft_strlen(*str) - 1;
	while (i > 0 && ((*str)[i] == '.' || (*str)[i] == '9'))
	{
		if ((*str)[i] != '.')
			(*str)[i] = '0';
		i--;
	}
	if ((*str)[i] != '-' && (*str)[i] != '9')
		(*str)[i] += 1;
	else if ((*str)[i] == '9')
		(*str)[i] = '0';
	if (((*str)[i] == '0' || (*str)[i] == '-') &&
		(nstr = ft_strnew(ft_strlen(*str) + 1)))
	{
		if ((*str)[i] == '-')
			nstr[i++] = '-';
		nstr[i++] = '1';
		ft_strcpy(&nstr[i], ((*str)[0] == '-') ? *str + 1 : *str);
		free(*str);
		*str = nstr;
	}
}

void			ft_putdecimalstr(char **str, double value, int precision)
{
	char		c;
	int			i;

	i = 0;
	while ((*str)[i] && (*str)[i] != '.')
		i++;
	i += ((*str)[i] == '.') ? 1 : 0;
	while (precision-- > 0)
	{
		value *= 10;
		c = (char)value % 10;
		value -= c;
		(*str)[i] = '0' + c;
		i++;
	}
	value *= 10;
	c = (char)value % 10;
	i -= (i > 0) ? 1 : 0;
	if (c >= 5 && c < 9 && (*str)[i] != '9' && (*str)[i] != '.')
		(*str)[i] += 1;
	else if (c == 9 || (c >= 5 && c < 9 && (*str)[i] == '9'))
		ajust_decimal(str);
}

char			*ft_dtoa(double value, int precision, char base)
{
	char		*str;
	int			len;
	int			point;

	point = (precision == -1) ? 0 : 1;
	precision = (!point) ? 0 : precision;
	len = ft_nblen_base((intmax_t)value, base);
	len += (value < 0 && (intmax_t)value == 0) ? 1 : 0;
	if (!(str = (char *)malloc(sizeof(*str) * (len + point + precision + 1))))
		return (NULL);
	str[len + point + precision] = '\0';
	ft_putnbstr(str, (intmax_t)value, len, base);
	value -= (intmax_t)value;
	if (value < 0)
		value *= -1;
	if (point)
		str[len++] = '.';
	ft_putdecimalstr(&str, value, precision);
	return (str);
}
