/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:43:41 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/30 15:41:11 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"
#include "ft_printf.h"

/*
** Simply present the champs
*/

static void		introduce_champs(t_champ *champions)
{
	ft_printf("Introducing contestants...\n");
	while (champions)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
					champions->player_nb, champions->program_len,
					champions->name, champions->comment);
		champions = champions->next;
	}
}

/*
** Add champ into the list champ or get options
** Check errors (nb champ)
** Create list process and load it in arena
*/

void			load_game(t_vm *env, int argc, char **argv)
{
	int		i;

	i = 0;
	env->dump = -1;
	while (++i != argc)
	{
		if (!load_player(env, argv[i]))
			if (!load_options(env, argc, argv, &i))
				ft_puterror("corewar: invalid argument\n");
	}
	if (env->options & PLAYER_NB)
		ft_puterror("corewar: not enough champion to asign the last number\n");
	if (!env->nb_champions)
		ft_puterror("corewar: there is not champion\n");
	sort_champs(env);
	create_champs_process(env);
	if (env->visual_option)
		init_ncurses(env);
	load_arena(env);
	introduce_champs(env->champions);
}
