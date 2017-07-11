/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 20:18:03 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/29 21:17:44 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <string.h>

# define ERROR			-1

# define NAME_ON		1
# define COMMENT_ON		2
# define LABEL_ON		3

/*
** structures
*/

typedef struct		s_buff
{
	unsigned char	*str;
	unsigned int	len;
	struct s_buff	*next;
}					t_buff;

typedef struct		s_call
{
	t_buff			*called;
	long			value;
	struct s_call	*next;
}					t_call;

typedef struct		s_label
{
	char			*name;
	long			value;
	t_call			*label_calls;
	struct s_label	*next;
}					t_label;

typedef struct		s_asm
{
	int				dot_s;
	int				dot_cor;
	int				addr;
	t_label			*label_start;
	t_label			*label_end;
	t_buff			*buff_end;
	t_buff			*buff_start;
	unsigned int	conditions: 3;
	int				cmd;
	int				arg;
	char			*line_start;
	int				line_nb;
	char			*dest;
}					t_asm;

typedef char		t_arg_type;

typedef struct		s_op
{
	char			*cmd;
	size_t			len;
	unsigned int	nb_params : 2;
	t_arg_type		args[3];
	unsigned char	op_code;
	unsigned int	restriction : 1;
	unsigned int	coding_byte : 1;
}					t_op;

/*
** .
*/

void				build_dot_cor(char *src);

/*
** build_header
*/

void				build_header(t_asm *env);

void				write_exec_magic(t_asm *env);
void				grep_name(t_asm *env, char *line);
void				grep_comment(t_asm *env, char *line);

/*
** build_cmd
*/

void				build_core(t_asm *env);

int					handle_cmd(t_asm *env, char **line);
t_op				g_tab[17];
void				register_cmd(t_asm *env, char **line);

unsigned char		handle_register(t_asm *env, char **line);
unsigned char		handle_index(t_asm *env, char **line);
unsigned char		handle_direct(t_asm *env, char **line);

void				write_label(t_asm *env);
void				nb_in_mem(unsigned char *str, int nb, size_t len);

/*
** build_label
*/

int					grep_label(t_asm *env, char **line);

void				potential_label(t_asm *env, char *line, size_t len, \
		size_t mem);
void				find_label(t_asm *env, char **line, size_t mem);
void				new_label(t_asm *env, char *line, size_t len);
void				new_call(t_asm *env, t_label *called, size_t mem);
t_label				*label_exist(t_asm *env, char *label_name, size_t len);

/*
** tools
*/

void				put_buff_in_new_file(t_asm *env);
void				new_buff(t_asm *env, unsigned char *str, unsigned int len);
void				skip_spaces(char **line);
void				ft_token(int line, int column, char *instr);
void				exit_error(t_asm *env, char *str);
void				exit_perror(t_asm *env, char *str, int i);

#endif
