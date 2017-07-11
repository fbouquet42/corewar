/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:00:28 by jmichaud          #+#    #+#             */
/*   Updated: 2016/12/29 20:14:39 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void			get_dollar(char **format, t_arg *arg)
{
	if (**format >= '1' && **format <= '9')
	{
		arg->dollar = ft_atoi(*format);
		while (ft_isdigit(**format))
			*format += 1;
		if (**format == '$')
			*format += 1;
		else
		{
			arg->field = arg->dollar;
			arg->dollar = 0;
		}
	}
}

int				dollar_conv(t_buffer *buf, t_arg *arg, t_funptr ptr_conv[])
{
	va_list		ap;
	int			ret;
	int			i;

	va_copy(ap, buf->ap_cp);
	i = 1;
	while (i++ < arg->dollar)
		ret = va_arg(ap, int);
	ret = ptr_conv[arg->fnum](ap, buf, arg);
	va_end(ap);
	return (ret);
}
