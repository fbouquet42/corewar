/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 10:53:12 by jmichaud          #+#    #+#             */
/*   Updated: 2016/12/19 11:36:59 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*ft_llitoa_base(long long int value, char base)
{
	const char		*tab = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char			*str;
	unsigned char	len;
	long long int	nb;

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
