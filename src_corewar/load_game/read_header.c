/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 20:25:40 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/27 14:55:02 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static void		magic_nb(unsigned char *mem)
{
	unsigned int	magic;
	unsigned char	*c;

	c = (unsigned char*)&magic;
	c[3] = mem[0];
	c[2] = mem[1];
	c[1] = mem[2];
	c[0] = mem[3];
	if (COREWAR_EXEC_MAGIC != magic)
		ft_puterror("corewar: magic number is missing\n");
}

static void		champ_len(t_champ *new, unsigned char *mem)
{
	unsigned char	*c;

	c = (unsigned char*)&new->program_len;
	c[3] = mem[0];
	c[2] = mem[1];
	c[1] = mem[2];
	c[0] = mem[3];
	if (!new->program_len)
		ft_puterror("corewar: champion is empty\n");
	if (new->program_len > CHAMP_MAX_SIZE)
		ft_puterror("corewar: champion is too big\n");
}

static void		champ_name(t_champ *new, char *name)
{
	size_t	len;

	len = ft_strnlen(name, PROG_NAME_LENGTH);
	if (!(new->name = ft_strnew(len)))
		ft_putperror("corewar", 1);
	ft_strncpy(new->name, name, len);
}

static void		champ_comment(t_champ *new, char *comment)
{
	size_t	len;

	len = ft_strnlen(comment, COMMENT_LENGTH);
	if (!(new->comment = ft_strnew(len)))
		ft_putperror("corewar", 1);
	ft_strncpy(new->comment, comment, len);
}

void			read_header(t_vm *env, int fd)
{
	int				rd;
	unsigned char	*buff;
	t_champ			*new;

	if (!(buff = (unsigned char*)ft_memalloc(PROG_NAME_LENGTH + \
					COMMENT_LENGTH + 8)))
		ft_putperror("corewar", 1);
	if ((rd = read(fd, buff, PROG_NAME_LENGTH + COMMENT_LENGTH + 8)) < 0)
		ft_putperror("corewar", 1);
	if (rd < PROG_NAME_LENGTH + COMMENT_LENGTH + 8)
		ft_puterror("corewar: header is too small\n");
	if (!(new = (t_champ*)ft_memalloc(sizeof(t_champ))))
		ft_putperror("corewar", 1);
	magic_nb(buff);
	champ_len(new, (buff + 4 + PROG_NAME_LENGTH));
	champ_name(new, (char*)(buff + 4));
	champ_comment(new, (char*)(buff + 8 + PROG_NAME_LENGTH));
	player_nb(env, new);
	new->next = env->champions;
	env->champions = new;
	free(buff);
}
