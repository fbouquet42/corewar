/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 16:00:02 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/29 21:48:05 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"
#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>

/*
** Check if the commands are corrects
** Ignore comments lines
** Put a token if an error occurs
*/

static void		handle_line(t_asm *env, char *line)
{
	while (*line == ' ' || *line == '\t')
		++line;
	if (!*line || *line == COMMENT_CHAR)
		return ;
	if (!handle_cmd(env, &line))
		handle_line(env, line);
	else
	{
		while (*line == ' ' || *line == '\t')
			++line;
		if (*line && *line != COMMENT_CHAR)
			ft_token(env->line_nb, (int)(line - env->line_start), line);
	}
}

/*
** Continue the t_buff chain list
** Read the file untill the end
** Then put the lengh of the champ in memory
*/

void			build_core(t_asm *env)
{
	char	*line;
	int		ret;

	env->addr = 0;
	while ((ret = get_next_line(env->dot_s, &line)))
	{
		if (ret == ERROR)
			exit_perror(env, "asm", 1);
		if (env->conditions & LABEL_ON)
			env->conditions ^= LABEL_ON;
		env->line_nb++;
		env->line_start = line;
		handle_line(env, line);
		free(line);
	}
	if (!env->addr)
		exit_error(env, "asm: champion is empty\n");
	nb_in_mem(env->buff_start->next->next->str, env->addr, 4);
	write_label(env);
}
