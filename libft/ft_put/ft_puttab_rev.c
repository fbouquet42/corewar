/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:48:25 by jmichaud          #+#    #+#             */
/*   Updated: 2017/01/10 17:14:08 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_puttab_rev(int *tab, uintmax_t size, char *str)
{
	while (--size > 0)
		ft_printf("%s[%d] = %d\n", str, size, tab[size]);
	ft_printf("%s[%d] = %d\n", str, size, tab[size]);
}
