/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_direct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 00:07:43 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/29 21:28:35 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "op.h"

static void			create_direct(t_asm *env, int nb)
{
	unsigned char	*str;

	if (g_tab[env->cmd].restriction)
	{
		if (!(str = (unsigned char*)ft_memalloc(2)))
			exit_perror(env, "asm", 1);
		nb = (short)nb;
		nb_in_mem(str, nb, 2);
		new_buff(env, str, 2);
	}
	else
	{
		if (!(str = (unsigned char*)ft_memalloc(4)))
			exit_perror(env, "asm", 1);
		nb_in_mem(str, nb, 4);
		new_buff(env, str, 4);
	}
}

unsigned char		handle_direct(t_asm *env, char **line)
{
	char	*buff;
	int		nb;

	++(*line);
	buff = *line;
	env->arg += g_tab[env->cmd].restriction ? 2 : 4;
	if (**line == LABEL_CHAR)
		find_label(env, line, g_tab[env->cmd].restriction ? 2 : 4);
	else
	{
		if (!(nb = ft_aatoi(line)) && (*line == buff || \
					(*buff == '-' && *line == buff + 1)))
			ft_token(env->line_nb, (int)(*line - env->line_start), *line);
		else
			create_direct(env, nb);
	}
	return (DIR_CODE);
}
