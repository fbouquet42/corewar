/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:37:56 by jmichaud          #+#    #+#             */
/*   Updated: 2017/02/02 14:05:16 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

intmax_t		ft_power(int nb, int p)
{
	intmax_t		result;

	if (p == 0)
		return (1);
	result = nb;
	while (--p > 0)
		result *= nb;
	return (nb);
}
