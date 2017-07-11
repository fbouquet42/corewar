/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 22:34:32 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/23 12:02:08 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"
#include "libft.h"

static unsigned char		register_params(t_asm *env, char **line)
{
	int				i;
	unsigned char	coding_byte;

	i = 0;
	coding_byte = 0;
	while (i != g_tab[env->cmd].nb_params)
	{
		skip_spaces(line);
		if (**line == 'r' && g_tab[env->cmd].args[i] & T_REG)
			coding_byte |= handle_register(env, line) << (6 - i * 2);
		else if (**line == DIRECT_CHAR && g_tab[env->cmd].args[i] & T_DIR)
			coding_byte |= handle_direct(env, line) << (6 - i * 2);
		else if (g_tab[env->cmd].args[i] & T_IND)
			coding_byte |= handle_index(env, line) << (6 - i * 2);
		else
			ft_token(env->line_nb, (int)(*line - env->line_start), *line);
		skip_spaces(line);
		++i;
		if (**line == SEPARATOR_CHAR && i != g_tab[env->cmd].nb_params)
			++(*line);
		else if (i != g_tab[env->cmd].nb_params)
			ft_token(env->line_nb, (int)(*line - env->line_start), *line);
	}
	return (coding_byte);
}

void						register_cmd(t_asm *env, char **line)
{
	t_buff		*coding_byte;

	skip_spaces(line);
	new_buff(env, (unsigned char*)ft_strndup((char*)&(g_tab[env->cmd].op_code),
				1, 1), 1);
	env->arg = 1;
	if (g_tab[env->cmd].coding_byte)
	{
		new_buff(env, (unsigned char*)ft_memalloc(1), 1);
		coding_byte = env->buff_end;
		env->arg += 1;
		*(coding_byte->str) |= register_params(env, line);
	}
	else
		register_params(env, line);
}
