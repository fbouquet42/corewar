/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:15:19 by jmichaud          #+#    #+#             */
/*   Updated: 2017/01/06 13:19:59 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_wstrlen(const wchar_t *s)
{
	size_t		len;

	len = 0;
	while (*s != '\0')
	{
		len += ft_wcharlen(*s);
		s++;
	}
	return (len);
}
