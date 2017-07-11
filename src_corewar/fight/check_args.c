/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:47:17 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/29 21:18:49 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

static void		restrict_idx(t_arg_value *ret)
{
	if (ret->type1 == T_IND)
		ret->arg1 %= IDX_MOD;
	if (ret->type2 == T_IND)
		ret->arg2 %= IDX_MOD;
	if (ret->type3 == T_IND)
		ret->arg3 %= IDX_MOD;
}

static int		reg_valid(t_arg_value *ret)
{
	if (ret->type1 == T_REG && (ret->arg1 > REG_NUMBER || \
			ret->arg1 <= 0))
		return (0);
	if (ret->type2 == T_REG && (ret->arg2 > REG_NUMBER || \
			ret->arg2 <= 0))
		return (0);
	if (ret->type3 == T_REG && (ret->arg3 > REG_NUMBER || \
			ret->arg3 <= 0))
		return (0);
	return (1);
}

t_arg_value		check_args(t_vm *env, t_process *p)
{
	t_arg_value		ret;
	unsigned char	coding_byte;

	ft_bzero((void*)&ret, sizeof(t_arg_value));
	coding_byte = *circ_mem(NULL, p->pc + 1);
	if (!parse_args(env, &ret, coding_byte, p) || !reg_valid(&ret))
		return (ret);
	if (g_tab[env->cur_cmd].idx_mod)
		restrict_idx(&ret);
	if (coding_byte & (255 >> (2 * g_tab[env->cur_cmd].nb_args)))
		return (ret);
	ret.pc = p->pc;
	ret.valid = 1;
	return (ret);
}
