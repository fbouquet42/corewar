/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:25:04 by jmichaud          #+#    #+#             */
/*   Updated: 2016/12/27 13:35:17 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int				conv_n(va_list ap, t_buffer *buf, t_arg *arg)
{
	int			*ptr;

	(void)arg;
	ptr = va_arg(ap, int *);
	*ptr = buf->i + buf->len;
	return (0);
}
