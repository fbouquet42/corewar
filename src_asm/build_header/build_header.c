/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 15:59:34 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/29 21:44:26 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>

/*
** Check if the name and the comment are corrects
** Ignore comments lines
*/

static void		handle_line(t_asm *env, char *line)
{
	while (*line == ' ' || *line == '\t')
		++line;
	if (!*line || *line == COMMENT_CHAR)
		return ;
	if (!(env->conditions & NAME_ON))
		grep_name(env, line);
	else
		grep_comment(env, line);
}

/*
** Begin the t_buff chain list with the magic
** Then read the file untill find name and comment
*/

void			build_header(t_asm *env)
{
	char	*line;
	int		ret;

	write_exec_magic(env);
	while ((ret = get_next_line(env->dot_s, &line)))
	{
		if (ret == ERROR)
			exit_error(env, "asm: can't read the file with gnl\n");
		env->line_nb++;
		env->line_start = line;
		handle_line(env, line);
		free(line);
		if (env->conditions & COMMENT_ON)
			break ;
	}
}
