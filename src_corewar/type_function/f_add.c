/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 23:50:33 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/27 01:47:19 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** add : opcode 4. OCP and take 3 T_REG.
** add T_REG 1 + 2 and stock the result at T_REG 3
** add can change the carry if result = 0.
*/

void		f_add(t_vm *env, t_process *p)
{
	t_arg_value			args;

	args = check_args(env, p);
	if (args.valid)
	{
		p->reg[args.arg3 - 1] = p->reg[args.arg1 - 1] + p->reg[args.arg2 - 1];
		if (!p->reg[args.arg3 - 1])
			p->carry = 1;
		else
			p->carry = 0;
		p->pc += args.len + 2;
	}
	else
		p->pc++;
	p->cmd = 0;
}
