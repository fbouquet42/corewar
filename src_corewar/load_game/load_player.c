/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 19:37:52 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/25 13:32:48 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

static int		valid_dot_cor(char *arg)
{
	size_t		len;

	len = ft_strlen(arg);
	if (len < 5 || !ft_strequ(arg + len - 4, ".cor"))
		return (0);
	return (1);
}

int				load_player(t_vm *env, char *arg)
{
	int		fd;

	if (!valid_dot_cor(arg))
		return (0);
	if (++env->nb_champions > MAX_PLAYERS)
		ft_puterror("too many champions\n");
	if ((fd = open(arg, O_RDONLY)) < 0)
		ft_putperror(arg, 1);
	read_header(env, fd);
	read_core(env, fd);
	close(fd);
	return (1);
}
