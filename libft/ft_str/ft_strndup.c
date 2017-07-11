/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 20:42:55 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/22 11:30:44 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strndup(char *str, unsigned int cpy, unsigned int len)
{
	char			*new;
	unsigned int	i;

	if (!(new = (char*)ft_memalloc(len)))
		return (NULL);
	i = 0;
	while (i < cpy)
	{
		new[i] = str[i];
		++i;
	}
	return (new);
}
