/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 11:46:44 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/27 17:24:29 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void			ft_token(int line, int column, char *instr)
{
	ft_printf("asm: %{FD}Syntax error at token [%03d:%03d]" \
			" instruction \"%s\"\n", \
			2, line, column, instr);
	exit(0);
}
