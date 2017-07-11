/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:41:38 by jmichaud          #+#    #+#             */
/*   Updated: 2017/01/27 18:53:27 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void			init_data2(t_funptr ptr_conv[])
{
	ptr_conv[15] = &conv_f;
	ptr_conv[16] = &conv_upf;
	ptr_conv[17] = &conv_b;
	ptr_conv[18] = &conv_n;
	ptr_conv[19] = &conv_e;
	ptr_conv[20] = &conv_upe;
	ptr_conv[21] = &conv_g;
	ptr_conv[22] = &conv_upg;
	ptr_conv[23] = &conv_r;
	ptr_conv[24] = &conv_upr;
	ptr_conv[25] = &conv_k;
	ptr_conv[26] = &conv_upk;
	ptr_conv[27] = &conv_a;
	ptr_conv[28] = &conv_a;
}

void			init_data(t_buffer *buf, t_funptr ptr_conv[])
{
	buf->i = 0;
	buf->len = 0;
	buf->fd = 1;
	ptr_conv[0] = &conv_percent;
	ptr_conv[1] = &conv_s;
	ptr_conv[2] = &conv_ups;
	ptr_conv[3] = &conv_p;
	ptr_conv[4] = &conv_d;
	ptr_conv[5] = &conv_upd;
	ptr_conv[6] = &conv_i;
	ptr_conv[7] = &conv_o;
	ptr_conv[8] = &conv_upo;
	ptr_conv[9] = &conv_u;
	ptr_conv[10] = &conv_upu;
	ptr_conv[11] = &conv_x;
	ptr_conv[12] = &conv_upx;
	ptr_conv[13] = &conv_c;
	ptr_conv[14] = &conv_upc;
	init_data2(ptr_conv);
}

/*
** create struct arg
** fill it with current arguments in the string
** call the function who match with ptr_conv
*/

int				put_arg(char **format, va_list ap, t_buffer *buf,
						t_funptr ptr_conv[])
{
	t_arg		arg;
	int			ret;

	*format += 1;
	ft_bzero(&arg, sizeof(arg));
	fill_arg(format, ap, &arg);
	if (**format == '\0' || arg.conversion == 0)
	{
		if (**format)
		{
			if (arg.left)
				fill_char_buff_left(&arg, buf, **format);
			else
				fill_char_buff_right(&arg, buf, **format);
		}
		else
			*format -= 1;
		return (1);
	}
	if (arg.dollar != 0)
		ret = dollar_conv(buf, &arg, ptr_conv);
	else
		ret = ptr_conv[arg.fnum](ap, buf, &arg);
	return (ret);
}

/*
** read each character of format
** get argument if there is a % and print it in buf
** else put current character in buf
** print buf before at the end of the function
*/

int				va_ft_printf(char *format, va_list ap)
{
	t_buffer	buf;
	t_funptr	ptr_conv[NB_FCT];

	init_data(&buf, ptr_conv);
	va_copy(buf.ap_cp, ap);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*(format + 1) == '{')
				add_code(&format, &buf, ap);
			else if (put_arg(&format, ap, &buf, ptr_conv) == -1)
				return (-1);
		}
		else
			putc_buf(*format, &buf);
		format++;
	}
	if (buf.i > 0)
		buf.len += put_buf(&buf);
	va_end(buf.ap_cp);
	return (buf.len);
}

/*
** get the argument pointer (ap)
** send it to secondary va_ft_printf to get the len
*/

int				ft_printf(const char *format, ...)
{
	int			len;
	va_list		ap;

	va_start(ap, format);
	len = va_ft_printf((char *)format, ap);
	va_end(ap);
	return (len);
}
