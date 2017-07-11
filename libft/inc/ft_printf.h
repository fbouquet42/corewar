/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:47:12 by jmichaud          #+#    #+#             */
/*   Updated: 2017/05/25 13:42:18 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# include <errno.h>

# define NB_FCT			29
# define PF_BUFF_SIZE	10000

typedef struct	s_arg
{
	int			dollar;
	int			sharp;
	int			zero;
	int			left;
	int			plus;
	int			space;
	int			thousand;
	int			field;
	int			isprecision;
	int			precision;
	char		len;
	char		conversion;
	int			fnum;
}				t_arg;

typedef struct	s_buffer
{
	unsigned char	buf[PF_BUFF_SIZE];
	int				i;
	int				len;
	int				fd;
	va_list			ap_cp;
}				t_buffer;

typedef int		(*t_funptr)(va_list ap, t_buffer *buf, t_arg *arg);

/*
** Mains functions
*/

int				ft_printf(const char *format, ...);
void			fill_arg(char **format, va_list ap, t_arg *arg);
void			add_code(char **format, t_buffer *buf, va_list ap);

/*
** Buffer gestion
*/

int				put_buf(t_buffer *buf);
void			putc_buf(unsigned char c, t_buffer *buf);
void			puts_buf(char *str, t_buffer *buf);
int				putint_buf(int c, t_buffer *buf);

/*
** Chech char in char_arg_list
*/

int				ft_isflag(char c);
int				ft_islen(char c);
int				ft_isprecision(char c);
int				ft_isconversion(char c);
int				ft_isarg(char c);

/*
** Functions for conversion
*/

int				conv_percent(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_s(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_ups(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_p(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_d(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_upd(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_i(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_o(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_upo(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_u(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_upu(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_x(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_upx(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_c(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_upc(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_f(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_upf(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_b(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_n(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_e(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_upe(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_g(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_upg(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_r(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_upr(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_k(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_upk(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_a(va_list ap, t_buffer *buf, t_arg *arg);
int				conv_upa(va_list ap, t_buffer *buf, t_arg *arg);

/*
** Functions to handle arguments
*/

uintmax_t		get_unsigned_nb(va_list ap, t_arg *arg);
char			*get_zero_str(int precision);
int				get_len_and_precision(t_arg *arg, char *str, intmax_t nb);
char			*thousand_separator(char *str, int number);

void			fill_buf_left(t_arg *arg, t_buffer *buf, int len, char *str);
void			fill_buf_right(t_arg *arg, t_buffer *buf, int len, char *str);

int				fill_char_buff_left(t_arg *arg, t_buffer *buf, wchar_t c);
int				fill_char_buff_right(t_arg *arg, t_buffer *buf, wchar_t c);

/*
** Dollar gestion
*/

void			get_dollar(char **format, t_arg *arg);
int				dollar_conv(t_buffer *buf, t_arg *arg, t_funptr ptr_conv[]);

void			ajust_precision(t_arg *arg, double nb);

/*
** Double gestion
*/

long double		get_double_nb(va_list ap, t_arg *arg);
int				get_exp(long double *nb);
void			power_str(char *str, char c, int e);
void			core_conv_e(t_buffer *buf, t_arg *arg, int len, char *str);

void			ft_errno_errors(int code, t_buffer *buf);

#endif
