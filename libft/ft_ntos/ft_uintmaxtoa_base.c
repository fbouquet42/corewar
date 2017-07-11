/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmaxtoa_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 10:53:12 by jmichaud          #+#    #+#             */
/*   Updated: 2016/12/21 16:30:56 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

char			*ft_uintmaxtoa_base(uintmax_t value, char base)
{
	const char			*tab = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char				*str;
	unsigned char		len;
	uintmax_t			nb;

	if (base < 2 || base > 36 || (nb = value) != value)
		return (NULL);
	len = 1;
	while (nb >= (uintmax_t)base)
	{
		nb /= base;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (value >= (uintmax_t)base)
	{
		str[--len] = tab[value % base];
		value /= base;
	}
	str[--len] = tab[value % base];
	return (str);
}
