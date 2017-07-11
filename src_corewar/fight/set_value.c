/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 23:33:20 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/27 15:23:01 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			set_value(int *value1, int *value2, t_arg_value *args, \
		t_process *p)
{
	if (args->type1 == T_IND)
		*value1 = get_arg(p->pc + args->arg1, 4);
	else if (args->type1 == T_REG)
		*value1 = p->reg[args->arg1 - 1];
	else
		*value1 = args->arg1;
	if (args->type2 == T_IND)
		*value2 = get_arg(p->pc + args->arg2, 4);
	else if (args->type2 == T_REG)
		*value2 = p->reg[args->arg2 - 1];
	else
		*value2 = args->arg2;
}
