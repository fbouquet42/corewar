/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:59:31 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/23 12:04:57 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"
#include <string.h>
#include "libft.h"

static size_t	len_of_label(char *line)
{
	size_t	len;

	len = 0;
	while (*line && ft_strchr(LABEL_CHARS, *line))
	{
		++len;
		++line;
	}
	return (len);
}

void			find_label(t_asm *env, char **line, size_t mem)
{
	size_t		len;
	t_label		*label;

	++(*line);
	if (!(len = len_of_label(*line)))
		ft_token(env->line_nb, (int)(*line - env->line_start), *line);
	if ((label = label_exist(env, *line, len)))
		new_call(env, label, mem);
	else
		potential_label(env, *line, len, mem);
	*line += len;
}
