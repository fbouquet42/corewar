/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:50:47 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/26 15:18:25 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		vm_usage(void)
{
	ft_putstr_fd("usage: ./corewar [-d -v] [[-n number] champion1.cor] ...\n",
																			2);
	exit(1);
}
