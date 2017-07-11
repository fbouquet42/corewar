/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_dot_cor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 23:26:17 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/29 21:30:08 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft_printf.h"

/*
** Check if there is ".s" at the end of the name
** Get the new name with ".cor"
*/

static char		*name_of_cor(char *src)
{
	char			*dest;
	unsigned int	len;

	len = ft_strlen(src);
	if (len < 3 || !ft_strequ(src + len - 2, ".s"))
		ft_puterror("asm: File format error, [.s] expected\n");
	if (!(dest = ft_strnew((len + 2))))
		ft_putperror("asm", 1);
	dest = ft_strncat(dest, src, (len - 2));
	dest = ft_strcat(dest, ".cor");
	return (dest);
}

/*
** Open the file and read datas in a buff:
** - header (name, comment)
** - core (instructions)
** Create the new ".cor" File
** Put the buffer in the new file and close everything
*/

void			build_dot_cor(char *src)
{
	t_asm		env;

	ft_bzero((void*)&env, sizeof(t_asm));
	env.dest = name_of_cor(src);
	if ((env.dot_s = open(src, O_RDONLY)) < 0)
		ft_putperror("asm", 1);
	build_header(&env);
	build_core(&env);
	if ((env.dot_cor = open(env.dest, O_CREAT | O_WRONLY \
					| O_TRUNC, S_IRUSR | S_IWUSR)) < 0)
		exit_perror(&env, "asm", 1);
	put_buff_in_new_file(&env);
	ft_printf("asm: sucess to compile %s in %s\n", src, env.dest);
	close(env.dot_s);
	close(env.dot_cor);
	free(env.dest);
}
