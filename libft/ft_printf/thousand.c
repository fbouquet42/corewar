/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thousand.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:43:44 by jmichaud          #+#    #+#             */
/*   Updated: 2017/01/18 18:58:57 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*thousand_separator(char *str, int number)
{
	char		*newstr;
	size_t		len;
	int			space;
	int			nb;

	len = ft_strlen(str);
	if (*str == '-')
		space = (len - 2) / number;
	else
		space = (len - 1) / number;
	if (!(newstr = ft_strnew(len + space)))
		return (NULL);
	nb = 0;
	while (len-- > 0)
	{
		newstr[len + space] = str[len];
		if (++nb == number && space > 0)
		{
			space--;
			newstr[len + space] = ',';
			nb = 0;
		}
	}
	free(str);
	return (newstr);
}
