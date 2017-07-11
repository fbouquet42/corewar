/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmaxtoa_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 10:53:12 by jmichaud          #+#    #+#             */
/*   Updated: 2016/12/28 18:59:15 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

char			*ft_intmaxtoa_base(intmax_t value, char base)
{
	const char		*tab = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char			*str;
	unsigned char	len;
	intmax_t		nb;

	if (base < 2 || base > 36 || (nb = value) != value)
		return (NULL);
	len = (value < 0 && base == 10) ? 2 : 1;
	while (nb >= base || nb <= -base)
	{
		nb /= base;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	str[0] = '-';
	nb = (value < 0) ? -1 : 1;
	while (value >= base || value <= -base)
	{
		str[--len] = tab[value % base * nb];
		value /= base;
	}
	str[--len] = tab[value % base * nb];
	return (str);
}
