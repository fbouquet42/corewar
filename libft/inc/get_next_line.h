/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:48:52 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/08 13:47:15 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_GNL 100
# define CHAR '\n'
# if BUFF_GNL < 1
#  error "BUFF_GNL must be superior to zero"
# endif
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft.h"

typedef struct	s_list_fd
{
	char				*s;
	char				*tmp;
	int					fd;
	int					ret;
	struct s_list_fd	*next;
}				t_list_fd;

int				get_next_line(const int fd, char **line);

#endif
