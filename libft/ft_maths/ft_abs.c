/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:34:22 by jmichaud          #+#    #+#             */
/*   Updated: 2017/02/02 14:05:10 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int		ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}