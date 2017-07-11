/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_exec_magic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 18:16:36 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/29 21:29:16 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"
#include "libft.h"

/*
** Create a str with the magic number
** Start the t_buff chain list with this str
*/

static unsigned char	*write_str(unsigned int magic, unsigned int len)
{
	unsigned char	*str;

	if (!(str = (unsigned char*)ft_memalloc(len)))
		ft_putperror("asm", 1);
	while (magic)
	{
		str[--len] = (unsigned char)(magic % 256);
		magic /= 256;
	}
	return (str);
}

void					write_exec_magic(t_asm *env)
{
	new_buff(env, write_str(COREWAR_EXEC_MAGIC, 4), 4);
}
