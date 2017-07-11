/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 20:52:46 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/24 20:55:52 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static int		player_nb_exist_somewhere_else(t_champ *champion, \
		t_champ *other_champions)
{
	while (other_champions)
	{
		if (other_champions != champion \
				&& other_champions->player_nb == champion->player_nb)
			return (1);
		other_champions = other_champions->next;
	}
	return (0);
}

static int		redefine_player_nb(t_vm *env, t_champ *champion)
{
	if (champion->player_nb_defined)
		return (1);
	champion->player_nb--;
	while (player_nb_exist_somewhere_else(champion, env->champions))
		champion->player_nb--;
	return (0);
}

static int		player_nb_exist(int new_nb, t_vm *env)
{
	t_champ		*champions;

	champions = env->champions;
	while (champions)
	{
		if (!(env->options & PLAYER_NB) && champions->player_nb == new_nb)
			return (1);
		else if (champions->player_nb == new_nb)
			return (redefine_player_nb(env, champions));
		champions = champions->next;
	}
	return (0);
}

void			player_nb(t_vm *env, t_champ *new)
{
	if (!(env->options & PLAYER_NB) && !player_nb_exist(-1, env))
		new->player_nb = -1;
	else if (!(env->options & PLAYER_NB))
	{
		new->player_nb = env->champions->player_nb - 1;
		while (player_nb_exist(new->player_nb, env))
			new->player_nb--;
	}
	else if (!player_nb_exist(env->opt_player_nb, env))
	{
		new->player_nb = env->opt_player_nb;
		new->player_nb_defined = 1;
		env->options ^= PLAYER_NB;
	}
	else
		ft_puterror("corewar: player number defined is already taken\n");
}
