/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_load.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 23:49:21 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/27 15:21:06 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		f_load(t_vm *env, t_process *p)
{
	t_arg_value			args;
	int					value;

	value = 0;
	args = check_args(env, p);
	if (args.valid)
	{
		if (args.type1 == T_IND)
			value = get_arg(p->pc + args.arg1, 4);
		else
			value = args.arg1;
		p->reg[args.arg2 - 1] = value;
		if (!value)
			p->carry = 1;
		else
			p->carry = 0;
		p->pc += args.len + 2;
	}
	else
		p->pc++;
	p->cmd = 0;
}
