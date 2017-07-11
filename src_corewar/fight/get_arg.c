/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:21:29 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/29 20:29:33 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	get_short_arg(int index)
{
	short				s;
	int					i;
	unsigned char		*c;

	i = 0;
	c = (unsigned char*)&s;
	c[0] = *circ_mem(NULL, index + 1);
	c[1] = *circ_mem(NULL, index);
	i = (int)s;
	return (i);
}

int			get_arg(int index, int len)
{
	int				ret;
	unsigned char	*c;
	int				i;

	if (len == 2)
		ret = get_short_arg(index);
	else
	{
		ret = 0;
		c = (unsigned char*)&ret;
		i = len;
		while (i--)
			c[i] = *circ_mem(NULL, index + (len - i - 1));
	}
	return (ret);
}
