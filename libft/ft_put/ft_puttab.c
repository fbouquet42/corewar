/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:48:25 by jmichaud          #+#    #+#             */
/*   Updated: 2017/01/10 17:14:08 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_puttab(int *tab, uintmax_t size, char *str)
{
	uintmax_t	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%s[%d] = %d\n", str, i, tab[i]);
		i++;
	}
}
