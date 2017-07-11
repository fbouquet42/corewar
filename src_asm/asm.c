/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 20:17:10 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/23 11:35:30 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

int			main(int argc, char **argv)
{
	if (argc != 2)
		ft_putstr_fd("usage: ./asm <sourcefile.s>\n", 2);
	else
		build_dot_cor(argv[1]);
	return (0);
}
