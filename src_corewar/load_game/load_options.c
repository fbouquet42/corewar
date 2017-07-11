/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 19:37:59 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/29 14:22:21 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static int		option_define_number(t_vm *env, int argc, \
		char **argv, int *i)
{
	if (ft_strequ(argv[*i], OPT_N))
	{
		if (!(*i + 1 < argc))
			ft_puterror("corewar: not enough argument to define" \
					" player number\n");
		*i += 1;
		env->opt_player_nb = ft_atoi(argv[*i]);
		env->options |= PLAYER_NB;
		return (1);
	}
	return (0);
}

static int		option_dump(t_vm *env, int argc, char **argv, int *i)
{
	if ((ft_strequ(argv[*i], OPT_D) || ft_strequ(argv[*i], OPT_DUMP)))
	{
		if (!(*i + 1 < argc))
			ft_puterror("corewar: not enough argument to parse dumping\n");
		*i += 1;
		env->dump = ft_atoi(argv[*i]);
		return (1);
	}
	return (0);
}

static int		option_visual(t_vm *env, char **argv, int *i)
{
	if (ft_strequ(argv[*i], OPT_V))
	{
		env->visual_option = 1;
		return (1);
	}
	return (0);
}

int				load_options(t_vm *env, int argc, char **argv, int *i)
{
	if (option_dump(env, argc, argv, i))
		return (1);
	if (option_define_number(env, argc, argv, i))
		return (1);
	if (option_visual(env, argv, i))
		return (1);
	return (0);
}
