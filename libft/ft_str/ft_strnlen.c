/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 22:40:14 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/24 13:02:11 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t			ft_strnlen(char *str, size_t len_max)
{
	size_t		len;

	len = 0;
	while (*str && len++ != len_max)
		++str;
	return (len);
}
