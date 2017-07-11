/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 14:51:55 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/29 21:28:29 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"
#include "libft.h"

static void			create_index(t_asm *env, int nb)
{
	unsigned char	*str;

	if (!(str = (unsigned char*)ft_memalloc(2)))
		exit_perror(env, "asm", 1);
	nb = (short)nb;
	nb_in_mem(str, nb, 2);
	new_buff(env, str, 2);
}

unsigned char		handle_index(t_asm *env, char **line)
{
	char	*buff;
	int		nb;

	env->arg += 2;
	buff = *line;
	if (**line == LABEL_CHAR)
		find_label(env, line, 2);
	else
	{
		if (!(nb = ft_aatoi(line)) && (*line == buff || \
					(*buff == '-' && *line == buff + 1)))
			ft_token(env->line_nb, (int)(*line - env->line_start), *line);
		else
			create_index(env, nb);
	}
	return (IND_CODE);
}
