/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 16:16:55 by jmichaud          #+#    #+#             */
/*   Updated: 2017/01/26 16:09:16 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <errno.h>

void			ft_errno_errors_3(int code, t_buffer *buf)
{
	if (code == EMFILE)
		puts_buf(": Too many open files\n", buf);
	else if (code == ENOTTY)
		puts_buf(": Not a typewriter\n", buf);
	else if (code == EFBIG)
		puts_buf(": File too large\n", buf);
	else if (code == ENOSPC)
		puts_buf(": No space left on device\n", buf);
	else if (code == ESPIPE)
		puts_buf(": Illegal seek\n", buf);
	else if (code == EROFS)
		puts_buf(": Read-only file system\n", buf);
	else if (code == EMLINK)
		puts_buf(": Too many links\n", buf);
	else if (code == EPIPE)
		puts_buf(": Broken pipe\n", buf);
	else if (code == EDOM)
		puts_buf(": Math argument out of domain of func\n", buf);
	else if (code == ERANGE)
		puts_buf(": Math result not representable\n", buf);
}

void			ft_errno_errors_2(int code, t_buffer *buf)
{
	if (code == ENOMEM)
		puts_buf(": Out of memory\n", buf);
	else if (code == EACCES)
		puts_buf(": Permission denied\n", buf);
	else if (code == EFAULT)
		puts_buf(": Bad address\n", buf);
	else if (code == EBUSY)
		puts_buf(": Device or resource busy\n", buf);
	else if (code == EEXIST)
		puts_buf(": File exists\n", buf);
	else if (code == EXDEV)
		puts_buf(": Cross-device link\n", buf);
	else if (code == ENODEV)
		puts_buf(": No such device\n", buf);
	else if (code == ENOTDIR)
		puts_buf(": Not a directory\n", buf);
	else if (code == EISDIR)
		puts_buf(": Is a directory\n", buf);
	else if (code == EINVAL)
		puts_buf(": Invalid argument\n", buf);
	else if (code == ENFILE)
		puts_buf(": File table overflow\n", buf);
	else
		ft_errno_errors_3(code, buf);
}

void			ft_errno_errors(int code, t_buffer *buf)
{
	if (code == EPERM)
		puts_buf(": Operation not permitted\n", buf);
	else if (code == ENOENT)
		puts_buf(": No such file or directory\n", buf);
	else if (code == ESRCH)
		puts_buf(": No such process\n", buf);
	else if (code == EINTR)
		puts_buf(": Interrupted system call\n", buf);
	else if (code == EIO)
		puts_buf(": I/O error\n", buf);
	else if (code == ENXIO)
		puts_buf(": No such device or address\n", buf);
	else if (code == E2BIG)
		puts_buf(": Argument list too long\n", buf);
	else if (code == ENOEXEC)
		puts_buf(": Exec format error\n", buf);
	else if (code == EBADF)
		puts_buf(": Bad file descriptor\n", buf);
	else if (code == ECHILD)
		puts_buf(": No child processes\n", buf);
	else if (code == EAGAIN)
		puts_buf(": Try again\n", buf);
	else
		ft_errno_errors_2(code, buf);
}
