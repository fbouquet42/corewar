/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldlen_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:07:05 by jmichaud          #+#    #+#             */
/*   Updated: 2017/01/26 12:07:25 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_ldlen_base(long double value, char base)
{
	int			len;

	len = (value < 0) ? 2 : 1;
	while (value >= base || value <= -base)
	{
		len++;
		value /= base;
	}
	return (len);
}
