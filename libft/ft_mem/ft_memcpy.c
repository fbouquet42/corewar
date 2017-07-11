/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:48:22 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/07 14:13:04 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	while (n-- > 0)
		((unsigned char*)dest)[n] = ((unsigned char*)src)[n];
	return (dest);
}
