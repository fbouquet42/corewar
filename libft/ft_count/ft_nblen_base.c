/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:27:27 by jmichaud          #+#    #+#             */
/*   Updated: 2017/01/04 15:21:03 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

int				ft_nblen_base(intmax_t nb, char base)
{
	int				len;

	len = (nb < 0) ? 2 : 1;
	while (nb >= base || nb <= -base)
	{
		nb /= base;
		len++;
	}
	return (len);
}
