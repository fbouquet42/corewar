/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grep_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:53:55 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/29 21:27:58 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "asm.h"

/*
** Check if the line start by COMMENT_CMD_STRING (op.h)
** Move untill find a "
** Search the next "
** Calcul the len of the comment and add it in the t_buff chain list
*/

void			grep_comment(t_asm *env, char *line)
{
	unsigned int	len;
	char			*next_quote;

	len = (unsigned int)ft_strlen(COMMENT_CMD_STRING);
	if (!ft_strnequ(line, COMMENT_CMD_STRING, len))
		ft_token(env->line_nb, (int)(line - env->line_start), line);
	line += len;
	while (*line == ' ' || *line == '\t')
		++line;
	if (*line != '\"')
		ft_token(env->line_nb, (int)(line - env->line_start), line);
	++line;
	if (!(next_quote = ft_strchr(line, (int)'\"')))
		exit_error(env, "asm: token \" missing to parse comment\n");
	if ((len = (unsigned int)(next_quote - line)) > COMMENT_LENGTH)
		exit_error(env, "asm: comment too long\n");
	new_buff(env, (unsigned char*)ft_strndup(line, len, \
				COMMENT_LENGTH), COMMENT_LENGTH);
	++next_quote;
	while (*next_quote == ' ' || *next_quote == '\t')
		++next_quote;
	if (*next_quote && *next_quote != COMMENT_CHAR)
		ft_token(env->line_nb, (int)(line - env->line_start), line);
	env->conditions |= COMMENT_ON;
}
