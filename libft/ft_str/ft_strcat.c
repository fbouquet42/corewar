/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:14:05 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/04 14:29:45 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char			*ft_strcat(char *s1, const char *s2)
{
	size_t		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	while (*s2 != '\0')
	{
		s1[i] = *s2;
		i++;
		s2++;
	}
	s1[i] = '\0';
	return (s1);
}
