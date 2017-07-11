/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:39:50 by jmichaud          #+#    #+#             */
/*   Updated: 2016/12/27 18:36:32 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

int				conv_percent(va_list ap, t_buffer *buf, t_arg *arg)
{
	char		*str;
	int			len;

	(void)ap;
	str = ft_strdup("%");
	if (!str)
		return (-1);
	len = 1;
	arg->precision = 0;
	if (arg->left)
		fill_buf_left(arg, buf, len, str);
	else
		fill_buf_right(arg, buf, len, str);
	free(str);
	return (0);
}
