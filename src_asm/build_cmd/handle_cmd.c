/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:58:00 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/31 13:11:49 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"
#include "libft.h"

t_op		g_tab[17] =
{
	{"live", 4, 1, {T_DIR, 0, 0}, 1, 0, 0},
	{"ldi", 3, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 1, 1},
	{"ld", 2, 2, {T_DIR | T_IND, T_REG, 0}, 2, 0, 1},
	{"sti", 3, 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 1, 1},
	{"st", 2, 2, {T_REG, T_IND | T_REG, 0}, 3, 0, 1},
	{"add", 3, 3, {T_REG, T_REG, T_REG}, 4, 0, 1},
	{"sub", 3, 3, {T_REG, T_REG, T_REG}, 5, 0, 1},
	{"and", 3, 3, \
		{T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 0, 1},
	{"or", 2, 3, \
		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 0, 1},
	{"xor", 3, 3, \
		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 0, 1},
	{"zjmp", 4, 1, {T_DIR, 0, 0}, 9, 1, 0},
	{"fork", 4, 1, {T_DIR, 0, 0}, 12, 1, 0},
	{"lldi", 4, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 1, 1},
	{"lld", 3, 2, {T_DIR | T_IND, T_REG, 0}, 13, 0, 1},
	{"lfork", 5, 1, {T_DIR, 0, 0}, 15, 1, 0},
	{"aff", 3, 1, {T_REG, 0, 0}, 16, 0, 1},
	{0, 0, 0, {0, 0, 0}, 0, 0, 0}
};

static void		grep_cmd(t_asm *env, char **line)
{
	int		i;

	i = 0;
	while (i != 16)
	{
		if (ft_strnequ(g_tab[i].cmd, *line, g_tab[i].len))
			break ;
		++i;
	}
	env->cmd = i;
	if (*(*line + g_tab[i].len) == LABEL_CHAR || !ft_memchr(" \t", \
				(int)*(*line + g_tab[i].len), 2))
		env->cmd = 16;
	else if (i != 16)
		*line += g_tab[i].len;
}

int				handle_cmd(t_asm *env, char **line)
{
	grep_cmd(env, line);
	if (env->cmd == 16)
		return (grep_label(env, line));
	register_cmd(env, line);
	return (42);
}
