/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 12:58:24 by jmichaud          #+#    #+#             */
/*   Updated: 2017/01/27 14:56:33 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_isflag(char c)
{
	if (c == '#' ||
		c == '0' ||
		c == '-' ||
		c == '+' ||
		c == ' ' ||
		c == '\'')
		return (1);
	else
		return (0);
}

int				ft_islen(char c)
{
	if (c == 'h' || c == 'H' ||
		c == 'l' || c == 'I' ||
		c == 'j' ||
		c == 'z' ||
		c == 'L')
		return (1);
	else
		return (0);
}

int				ft_isprecision(char c)
{
	if (c == '.' ||
		(c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

int				ft_isconversion(char c)
{
	if (c == '%' ||
		c == 's' || c == 'S' ||
		c == 'p' ||
		c == 'd' || c == 'D' || c == 'i' ||
		c == 'o' || c == 'O' ||
		c == 'u' || c == 'U' ||
		c == 'x' || c == 'X' ||
		c == 'c' || c == 'C' ||
		c == 'f' || c == 'F' ||
		c == 'b' ||
		c == 'n' ||
		c == 'e' || c == 'E' ||
		c == 'g' || c == 'G' ||
		c == 'r' || c == 'R' ||
		c == 'k' || c == 'K' ||
		c == 'a' || c == 'A')
		return (1);
	else
		return (0);
}

int				ft_isarg(char c)
{
	if (ft_isflag(c) ||
		ft_islen(c) ||
		ft_isprecision(c) ||
		ft_isconversion(c))
		return (1);
	else
		return (0);
}
