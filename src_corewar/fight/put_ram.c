/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ram.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 02:57:13 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/27 15:17:38 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		put_ram(int index, int to_put)
{
	unsigned char		*c;
	int					i;

	i = 4;
	c = (unsigned char*)&to_put;
	while (i--)
		*circ_mem(NULL, index + 3 - i) = c[i];
}
