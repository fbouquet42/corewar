/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_code.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:41:38 by jmichaud          #+#    #+#             */
/*   Updated: 2017/01/25 18:20:32 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void			put_color_number(char **format, t_buffer *buf, char c)
{
	if (*(*format - 1) != '{')
		putc_buf(';', buf);
	if (**format == '#')
		*format += 1;
	putc_buf(c, buf);
	if (**format == 'B' && *(*format + 1) == 'L' && *(*format + 2) == 'A')
		putc_buf('0', buf);
	else if (**format == 'R')
		putc_buf('1', buf);
	else if (**format == 'G')
		putc_buf('2', buf);
	else if (**format == 'Y')
		putc_buf('3', buf);
	else if (**format == 'B')
		putc_buf('4', buf);
	else if (**format == 'P')
		putc_buf('5', buf);
	else if (**format == 'C')
		putc_buf('6', buf);
	else
		putc_buf('7', buf);
}

void			add_color(char **format, t_buffer *buf)
{
	const char	*colortab = "BRGYPCW";

	puts_buf("\033[", buf);
	while (**format == '!' || **format == '*' || **format == '_')
	{
		if (**format == '!')
			putc_buf('0', buf);
		else if (**format == '*')
			putc_buf('1', buf);
		else
			putc_buf('4', buf);
		*format += 1;
		if (**format == '!' || **format == '*' || **format == '_')
			putc_buf(';', buf);
	}
	if (**format == '#' && ft_strchr(colortab, *(*format + 1)) != NULL)
		put_color_number(format, buf, '4');
	else if (ft_strchr(colortab, **format) != NULL)
		put_color_number(format, buf, '3');
	else if (**format != '}')
		putc_buf('0', buf);
	putc_buf('m', buf);
}

void			add_code(char **format, t_buffer *buf, va_list ap)
{
	*format += 2;
	if (**format == 'S')
		ft_putstr_fd("[1]    42666 segmentation fault  ./joke\n", 2);
	else if (**format == 'E')
		ft_errno_errors(errno, buf);
	else if (**format == 'C' && *(*format + 1) == 'L')
		puts_buf("\033[H\033[2J", buf);
	else if (**format == 'F' && *(*format + 1) == 'D')
		buf->fd = va_arg(ap, int);
	else if (ft_isdigit(**format))
	{
		puts_buf("\033[", buf);
		while (ft_isdigit(**format))
		{
			putc_buf(**format, buf);
			*format += 1;
		}
		putc_buf('G', buf);
	}
	else
		add_color(format, buf);
	while (**format && **format != '}')
		*format += 1;
	if (**format == '\0')
		*format -= 1;
}
