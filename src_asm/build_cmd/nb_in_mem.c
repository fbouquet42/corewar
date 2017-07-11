/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_in_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 14:36:34 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/29 21:42:42 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** MAJ: add protection len > 0
*/

void		nb_in_mem(unsigned char *str, unsigned int nb, size_t len)
{
	while (nb)
	{
		if (len > 0)
			str[--len] = nb % 256;
		nb /= 256;
	}
}
