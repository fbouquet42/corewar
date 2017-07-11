/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_register.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 00:10:24 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/29 21:28:21 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"
#include "op.h"

unsigned char		handle_register(t_asm *env, char **line)
{
	int				nb;
	unsigned char	*str;
	char			*buff;

	env->arg++;
	++(*line);
	buff = *line;
	if ((!(nb = ft_aatoi(line)) && *line == buff) || *buff == '-')
		ft_token(env->line_nb, (int)(buff - env->line_start), buff);
	if (!(str = (unsigned char*)ft_memalloc(1)))
		exit_perror(env, "asm", 1);
	nb = (short)nb;
	nb_in_mem(str, nb, 1);
	new_buff(env, str, 1);
	return (REG_CODE);
}
