/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 21:06:44 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/29 21:19:27 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		valid_arg(unsigned char cur_cmd, unsigned char bits, int i, \
		t_arg_value *ret)
{
	if (bits == REG_CODE && !(g_tab[cur_cmd].args[i] & T_REG))
		return (0);
	else if (bits == DIR_CODE && !(g_tab[cur_cmd].args[i] & T_DIR))
		return (0);
	else if (bits == IND_CODE && !(g_tab[cur_cmd].args[i] & T_IND))
		return (0);
	else if (bits == REG_CODE)
		((unsigned char*)ret)[12 + i] = T_REG;
	else if (bits == DIR_CODE)
		((unsigned char*)ret)[12 + i] = T_DIR;
	else if (bits == IND_CODE)
		((unsigned char*)ret)[12 + i] = T_IND;
	return (42);
}

int				parse_args(t_vm *env, t_arg_value *ret, \
		unsigned char coding_byte, t_process *p)
{
	int				i;
	unsigned char	bits;

	i = 0;
	while (i != g_tab[env->cur_cmd].nb_args)
	{
		bits = (coding_byte >> ((3 - i) * 2)) & 3;
		if (!valid_arg(env->cur_cmd, bits, i, ret))
			return (0);
		if (bits == REG_CODE)
			((int*)ret)[i] = get_arg(p->pc + 2 + ret->len++, 1);
		else if (bits == DIR_CODE)
		{
			((int*)ret)[i] = get_arg(p->pc + 2 + ret->len, \
				g_tab[env->cur_cmd].restriction ? 2 : 4);
			ret->len += g_tab[env->cur_cmd].restriction ? 2 : 4;
		}
		else if (bits == IND_CODE)
		{
			((int*)ret)[i] = get_arg(p->pc + 2 + ret->len, 2);
			ret->len += 2;
		}
		++i;
	}
	return (42);
}
