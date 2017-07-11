/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 11:11:46 by jmichaud          #+#    #+#             */
/*   Updated: 2016/12/28 11:29:06 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

int				ft_wcharlen(wchar_t c)
{
	if (c < 128)
		return (1);
	else if (c < 2048)
		return (2);
	else if (c < 65536)
		return (3);
	else if (c < 2097152)
		return (4);
	else
		return (0);
}
