/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unblen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:27:27 by jmichaud          #+#    #+#             */
/*   Updated: 2017/01/06 16:56:09 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

int				ft_unblen_base(uintmax_t nb, unsigned char base)
{
	int				len;

	len = 1;
	while (nb >= base)
	{
		nb /= base;
		len++;
	}
	return (len);
}
