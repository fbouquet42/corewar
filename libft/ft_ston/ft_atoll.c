/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:51:56 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/04 11:23:48 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_atoll(const char *str)
{
	long long int	result;
	char			sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (sign * (*str - '0'));
		str++;
	}
	return (result);
}
