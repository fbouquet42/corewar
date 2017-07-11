# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 12:34:56 by jmichaud          #+#    #+#              #
#    Updated: 2017/05/29 19:23:11 by jtoty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## V A R I A B L E S
#####################
NAME			=	libft.a

P_INC			=	./inc/
P_OBJ			=	./obj/

O_FT_COUNT		=	$(addprefix $(P_OBJ), $(S_FT_COUNT:.c=.o))
P_FT_COUNT		=	./ft_count/
S_FT_COUNT		=	\
					ft_get_exp_base.c		\
					ft_ldlen_base.c			\
					ft_nblen_base.c			\
					ft_nbwords.c			\
					ft_strlen.c				\
					ft_unblen_base.c		\
					ft_wcharlen.c			\
					ft_wordlen.c			\
					ft_wstrlen.c

O_FT_IS			=	$(addprefix $(P_OBJ), $(S_FT_IS:.c=.o))
P_FT_IS			=	./ft_is/
S_FT_IS			=	\
					ft_isalnum.c			\
					ft_isalpha.c			\
					ft_isascii.c			\
					ft_isblank.c			\
					ft_iscntrl.c			\
					ft_isdigit.c			\
					ft_isgraph.c			\
					ft_islower.c			\
					ft_isprint.c			\
					ft_isspace.c			\
					ft_isupper.c			\
					ft_isxdigit.c			\
					ft_str_isalpha.c		\
					ft_str_isdigit.c		\
					ft_str_islower.c		\
					ft_str_isprint.c		\
					ft_str_isupper.c

O_FT_LST		=	$(addprefix $(P_OBJ), $(S_FT_LST:.c=.o))
P_FT_LST		=	./ft_lst/
S_FT_LST		=	\
					ft_del_content.c		\
					ft_lst_push_back.c		\
					ft_lstadd.c				\
					ft_lstdel.c				\
					ft_lstdelone.c			\
					ft_lstiter.c			\
					ft_lstmap.c				\
					ft_lstnew.c

O_FT_MATHS		=	$(addprefix $(P_OBJ), $(S_FT_MATHS:.c=.o))
P_FT_MATHS		=	./ft_maths/
S_FT_MATHS		=	\
					ft_abs.c				\
					ft_abs_dbl.c			\
					ft_power.c				\
					ft_square.c

O_FT_MEM		=	$(addprefix $(P_OBJ), $(S_FT_MEM:.c=.o))
P_FT_MEM		=	./ft_mem/
S_FT_MEM		=	\
					ft_bzero.c				\
					ft_memalloc.c			\
					ft_memccpy.c			\
					ft_memchr.c				\
					ft_memcmp.c				\
					ft_memcpy.c				\
					ft_memdel.c				\
					ft_memmove.c			\
					ft_memset.c

O_FT_NTOS		=	$(addprefix $(P_OBJ), $(S_FT_NTOS:.c=.o))
P_FT_NTOS		=	./ft_ntos/
S_FT_NTOS		=	\
					ft_dtoa.c				\
					ft_intmaxtoa_base.c		\
					ft_itoa.c				\
					ft_itoa_base.c			\
					ft_ldtoa.c				\
					ft_llitoa_base.c		\
					ft_uintmaxtoa_base.c	\
					ft_ullitoa_base.c

O_FT_PRINTF		=	$(addprefix $(P_OBJ), $(S_FT_PRINTF:.c=.o))
P_FT_PRINTF		=	./ft_printf/
S_FT_PRINTF		=	\
					add_code.c				\
					buffer.c				\
					conv_a.c				\
					conv_b.c				\
					conv_c.c				\
					conv_d.c				\
					conv_e.c				\
					conv_f.c				\
					conv_g.c				\
					conv_k.c				\
					conv_n.c				\
					conv_o.c				\
					conv_p.c				\
					conv_percent.c			\
					conv_r.c				\
					conv_s.c				\
					conv_u.c				\
					conv_x.c				\
					dollar.c				\
					ft_errno_errors.c		\
					fill_arg.c				\
					fill_buf.c				\
					ft_is_arg.c				\
					ft_printf.c				\
					thousand.c

O_FT_PUT		=	$(addprefix $(P_OBJ), $(S_FT_PUT:.c=.o))
P_FT_PUT		=	./ft_put/
S_FT_PUT		=	\
					ft_putchar.c			\
					ft_putchar_fd.c			\
					ft_putendl.c			\
					ft_putendl_fd.c			\
					ft_puterror.c			\
					ft_putperror.c			\
					ft_putnbr.c				\
					ft_putnbr_fd.c			\
					ft_putnstr_fd.c			\
					ft_putstr.c				\
					ft_putstr_fd.c			\
					ft_puttab_rev.c			\
					ft_puttab.c

O_FT_STON		=	$(addprefix $(P_OBJ), $(S_FT_STON:.c=.o))
P_FT_STON		=	./ft_ston/
S_FT_STON		=	\
					ft_atoi.c				\
					ft_aatoi.c				\
					ft_atol.c				\
					ft_atoll.c

O_FT_STR		=	$(addprefix $(P_OBJ), $(S_FT_STR:.c=.o))
P_FT_STR		=	./ft_str/
S_FT_STR		=	\
					ft_strcapitalize.c		\
					ft_strcat.c				\
					ft_strchr.c				\
					ft_strclr.c				\
					ft_strcmp.c				\
					ft_strcpy.c				\
					ft_strdel.c				\
					ft_strdup.c				\
					ft_strequ.c				\
					ft_striter.c			\
					ft_striteri.c			\
					ft_strjoin.c			\
					ft_strlcat.c			\
					ft_strlcpy.c			\
					ft_strlowcase.c			\
					ft_strmap.c				\
					ft_strmapi.c			\
					ft_strncat.c			\
					ft_strncmp.c			\
					ft_strncpy.c			\
					ft_strndup.c			\
					ft_strnequ.c			\
					ft_strnew.c				\
					ft_strnlen.c			\
					ft_strnstr.c			\
					ft_strrchr.c			\
					ft_strsplit.c			\
					ft_strstr.c				\
					ft_strsub.c				\
					ft_strtrim.c			\
					ft_strupcase.c			\
					ft_tolower.c			\
					ft_toupper.c

O_GNL			=	$(addprefix $(P_OBJ), $(S_GNL:.c=.o))
P_GNL			=	./get_next_line/
S_GNL			=	\
					get_next_line.c			\

## C O M P I L E R
###################
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
CPPFLAGS		=	-I$(P_INC)

## F U N C T I O N S
#####################

define compile_obj
	@mkdir $(P_OBJ) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $(2) -o $(1)
	@echo -n ✓
endef

## R U L E S
#############
.PHONY			:	all clean fclean re

all				:	$(NAME)

$(NAME)			:	\
					$(O_FT_COUNT)	\
					$(O_FT_IS)		\
					$(O_FT_LST)		\
					$(O_FT_MATHS)	\
					$(O_FT_MEM)		\
					$(O_FT_NTOS)	\
					$(O_FT_PRINTF)	\
					$(O_FT_PUT)		\
					$(O_FT_STON)	\
					$(O_FT_STR)		\
					$(O_GNL)
	@echo "\nobj\t\t...$(GREEN)done$(NC)"
	@echo -n libft.a
	@ar rc $@ $^
	@echo "\t\t...$(GREEN)done$(NC)"
	@echo -n ranlib
	@ranlib $@
	@echo "\t\t...$(GREEN)done$(NC)"

$(P_OBJ)%.o	:	$(P_FT_COUNT)%.c $(P_INC) Makefile
	$(call compile_obj, $@, $<)

$(P_OBJ)%.o	:	$(P_FT_IS)%.c $(P_INC) Makefile
	$(call compile_obj, $@, $<)

$(P_OBJ)%.o	:	$(P_FT_LST)%.c $(P_INC) Makefile
	$(call compile_obj, $@, $<)

$(P_OBJ)%.o	:	$(P_FT_MATHS)%.c $(P_INC) Makefile
	$(call compile_obj, $@, $<)

$(P_OBJ)%.o	:	$(P_FT_MEM)%.c $(P_INC) Makefile
	$(call compile_obj, $@, $<)

$(P_OBJ)%.o	:	$(P_FT_NTOS)%.c $(P_INC) Makefile
	$(call compile_obj, $@, $<)

$(P_OBJ)%.o	:	$(P_FT_PRINTF)%.c $(P_INC) Makefile
	$(call compile_obj, $@, $<)

$(P_OBJ)%.o	:	$(P_FT_PUT)%.c $(P_INC) Makefile
	$(call compile_obj, $@, $<)

$(P_OBJ)%.o	:	$(P_FT_STON)%.c $(P_INC) Makefile
	$(call compile_obj, $@, $<)

$(P_OBJ)%.o	:	$(P_FT_STR)%.c $(P_INC) Makefile
	$(call compile_obj, $@, $<)

$(P_OBJ)%.o	:	$(P_GNL)%.c $(P_INC) Makefile
	$(call compile_obj, $@, $<)

clean			:
	@echo -n clean lib
	@rm -f $(O_FT_COUNT)
	@rm -f $(O_FT_IS)
	@rm -f $(O_FT_LST)
	@rm -f $(O_FT_MATHS)
	@rm -f $(O_FT_MEM)
	@rm -f $(O_FT_NTOS)
	@rm -f $(O_FT_PRINTF)
	@rm -f $(O_FT_PUT)
	@rm -f $(O_FT_STON)
	@rm -f $(O_FT_STR)
	@rm -f $(O_GNL)
	@rmdir $(P_OBJ) 2> /dev/null || true
	@echo "\t...$(YELLOW)done$(NC)"

fclean			:	clean
	@echo -n fclean lib
	@rm -f $(NAME)
	@echo "\t...$(RED)done$(NC)"

re				:	fclean
	@make

## C O L O R S
###############
NC				=	\033[0m
BOLD			=	\033[1m
UNDERLINE		=	\033[4m

BLACK			=	\033[30m
RED				=	\033[31m
GREEN			=	\033[32m
YELLOW			=	\033[33m
BLUE			=	\033[34m
PURPLE			=	\033[35m
CYAN			=	\033[36m
WHITE			=	\033[37m

## E D I T I O N
#################
UP_NAME			=	$(shell echo $(NAME) | tr '[:lower:]' '[:upper:]')
