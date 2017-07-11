/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_ind_store.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 23:54:39 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/30 15:10:34 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		f_ind_store(t_vm *env, t_process *p)
{
	t_arg_value			args;
	int					value2;
	int					value3;

	args = check_args(env, p);
	if (args.valid)
	{
		if (args.type2 == T_IND)
			value2 = get_arg(p->pc + args.arg2, 4);
		else if (args.type2 == T_REG)
			value2 = p->reg[args.arg2 - 1];
		else
			value2 = args.arg2;
		if (args.type3 == T_REG)
			value3 = p->reg[args.arg3 - 1];
		else
			value3 = args.arg3;
		put_ram(p->pc + value2 + value3, p->reg[args.arg1 - 1]);
		if (env->visual_option)
			pre_modif_arena(env, p->pc + value2 + value3, p->player_color);
		p->pc += args.len + 2;
	}
	else
		p->pc++;
	p->cmd = 0;
}
