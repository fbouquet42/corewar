/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 10:53:12 by jmichaud          #+#    #+#             */
/*   Updated: 2016/12/21 16:31:38 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*ft_ullitoa_base(unsigned long long int value, char base)
{
	const char				*tab = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char					*str;
	unsigned char			len;
	unsigned long long int	nb;

	if (base < 2 || base > 36 || (nb = value) != value)
		return (NULL);
	len = 1;
	while (nb >= (unsigned long long int)base)
	{
		nb /= base;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (value >= (unsigned long long int)base)
	{
		str[--len] = tab[value % base];
		value /= base;
	}
	str[--len] = tab[value % base];
	return (str);
}
