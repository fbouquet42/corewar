/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 12:47:58 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/27 15:22:40 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned char		*circ_mem(unsigned char *param, int index)
{
	static unsigned char	*mem = NULL;

	if (!mem)
		return ((mem = (unsigned char*)param));
	while (index < 0)
		index += MEM_SIZE;
	if (index >= MEM_SIZE)
		index %= MEM_SIZE;
	return (mem + index);
}
