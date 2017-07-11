/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_aff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:45:05 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/30 15:39:49 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "ft_printf.h"

void			f_aff(t_vm *env, t_process *p)
{
	unsigned int		param;
	unsigned char		coding_byte;

	(void)env;
	coding_byte = *circ_mem(NULL, p->pc + 1);
	param = (unsigned int)get_arg(p->pc + 2, 4);
	p->pc += 6;
	p->cmd = 0;
	if (param <= 255 && !(coding_byte & 191) && coding_byte & 64 &&
		!env->visual_option)
		ft_printf("Player %d says \"%c\"", p->player_color - 9, (char)param);
}
