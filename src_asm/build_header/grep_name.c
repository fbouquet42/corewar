/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grep_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:52:24 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/29 21:27:47 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"
#include "op.h"

/*
** Check if the line start by NAME_CMD_STRING (op.h)
** Move untill find a "
** Search the next "
** Calcul the len of the comment and add it in the t_buff chain list
*/

void			grep_name(t_asm *env, char *line)
{
	unsigned int	len;
	char			*next_quote;

	len = (unsigned int)ft_strlen(NAME_CMD_STRING);
	if (!ft_strnequ(line, NAME_CMD_STRING, len))
		ft_token(env->line_nb, (int)(line - env->line_start), line);
	line += len;
	while (*line == ' ' || *line == '\t')
		++line;
	if (*line != '\"')
		ft_token(env->line_nb, (int)(line - env->line_start), line);
	++line;
	if (!(next_quote = ft_strchr(line, (int)'\"')))
		exit_error(env, "asm: token \" missing to parse name\n");
	if ((len = (unsigned int)(next_quote - line)) > PROG_NAME_LENGTH)
		exit_error(env, "asm: name too long\n");
	new_buff(env, (unsigned char*)ft_strndup(line, len, \
				PROG_NAME_LENGTH), PROG_NAME_LENGTH);
	++next_quote;
	while (*next_quote == ' ' || *next_quote == '\t')
		++next_quote;
	if (*next_quote && *next_quote != COMMENT_CHAR)
		ft_token(env->line_nb, (int)(line - env->line_start), line);
	new_buff(env, (unsigned char*)ft_memalloc(4), (unsigned int)4);
	env->conditions |= NAME_ON;
}
