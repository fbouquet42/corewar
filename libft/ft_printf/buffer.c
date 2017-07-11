/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:00:28 by jmichaud          #+#    #+#             */
/*   Updated: 2017/01/24 14:09:23 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

int				put_buf(t_buffer *buf)
{
	write(buf->fd, buf->buf, buf->i);
	return (buf->i);
}

void			putc_buf(unsigned char c, t_buffer *buf)
{
	buf->buf[buf->i] = c;
	buf->i += 1;
	if (buf->i == PF_BUFF_SIZE)
	{
		buf->len += put_buf(buf);
		buf->i = 0;
	}
}

void			puts_buf(char *str, t_buffer *buf)
{
	while (*str)
	{
		putc_buf(*str, buf);
		str++;
	}
}

/*
** 0xxxxxxx : 2^7
** 110xxxxx 10xxxxxx : 2^11
** 1110xxxx 10xxxxxx 10xxxxxx : 2^16
** 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx : 2^21
**
** 00111111 = 63
** 10000000 = 128
** 11000000 = 192
** 11100000 = 224
** 11110000 = 240
*/

int				putint_buf(int c, t_buffer *buf)
{
	if (c > 1114111 || (c >= 0xD800 && c <= 0xDFFF) ||
		(MB_CUR_MAX == 1 && c > 255))
		return (-1);
	if ((c < 128 && MB_CUR_MAX > 1) ||
		(c < 256 && MB_CUR_MAX == 1))
		putc_buf((unsigned char)c, buf);
	else if (c < 2048)
	{
		putc_buf(((c >> 6) | 192), buf);
		putc_buf(((c & 63) | 128), buf);
	}
	else if (c < 65536)
	{
		putc_buf(((c >> 12) | 224), buf);
		putc_buf((((c >> 6) & 63) | 128), buf);
		putc_buf(((c & 63) | 128), buf);
	}
	else if (c < 1114112)
	{
		putc_buf(((c >> 18) | 240), buf);
		putc_buf((((c >> 12) & 63) | 128), buf);
		putc_buf((((c >> 6) & 63) | 128), buf);
		putc_buf(((c & 63) | 128), buf);
	}
	return (0);
}
