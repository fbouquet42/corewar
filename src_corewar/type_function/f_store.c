/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_store.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 23:50:05 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/30 15:10:10 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		f_store(t_vm *env, t_process *p)
{
	t_arg_value			args;

	args = check_args(env, p);
	if (args.valid)
	{
		if (args.type2 == T_IND)
		{
			put_ram(p->pc + args.arg2, p->reg[args.arg1 - 1]);
			if (env->visual_option)
				pre_modif_arena(env, p->pc + args.arg2, p->player_color);
		}
		else
			p->reg[args.arg2 - 1] = p->reg[args.arg1 - 1];
		p->pc += args.len + 2;
	}
	else
		p->pc++;
	p->cmd = 0;
}
