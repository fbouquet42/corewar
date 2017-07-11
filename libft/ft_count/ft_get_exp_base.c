/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_exp_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:26:38 by jmichaud          #+#    #+#             */
/*   Updated: 2017/05/16 13:32:00 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				get_exp_base(long double *nb, char base)
{
	int			e;

	e = 0;
	while ((*nb > 0 && *nb < 1) || (*nb < 0 && *nb > -1))
	{
		*nb *= base;
		e--;
	}
	while (*nb >= base || *nb <= -base)
	{
		*nb /= base;
		e++;
	}
	return (e);
}
