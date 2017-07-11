/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grep_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 19:35:03 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/23 12:00:33 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "libft.h"

static char		*chr_end_label(char *line)
{
	while (*line)
	{
		if (*line == LABEL_CHAR)
			return (line);
		if (!ft_strchr(LABEL_CHARS, (int)*line))
			return (NULL);
		++line;
	}
	return (NULL);
}

int				grep_label(t_asm *env, char **line)
{
	size_t		len;
	char		*end_label;

	if (!(end_label = chr_end_label(*line)))
		ft_token(env->line_nb, (int)(*line - env->line_start), *line);
	if (env->conditions & LABEL_ON)
		ft_token(env->line_nb, (int)(*line - env->line_start), *line);
	len = end_label - *line;
	if (!len)
		ft_token(env->line_nb, (int)(*line - env->line_start), *line);
	new_label(env, *line, len);
	*line += (len + 1);
	env->conditions |= LABEL_ON;
	return (0);
}
