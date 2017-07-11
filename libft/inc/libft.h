/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:10:07 by jmichaud          #+#    #+#             */
/*   Updated: 2017/05/25 13:44:33 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdint.h>
# include <wchar.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
** ft_count
*/

int				ft_ldlen_base(long double value, char base);
int				ft_nblen_base(intmax_t nb, char base);
int				ft_unblen_base(uintmax_t nb, char base);

size_t			ft_strlen(const char *str);
size_t			ft_wstrlen(const wchar_t *wstr);

size_t			ft_nbwords(const char *str, char c);
int				ft_wcharlen(wchar_t c);
size_t			ft_wordlen(const char *str, char c);

int				get_exp_base(long double *nb, char base);

/*
** ft_is
*/

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isblank(int c);
int				ft_iscntrl(int c);
int				ft_isdigit(int c);
int				ft_isgraph(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_isxdigit(int c);

int				ft_str_isalpha(const char *str);
int				ft_str_islower(const char *str);
int				ft_str_isdigit(const char *str);
int				ft_str_isprint(const char *str);
int				ft_str_isupper(const char *str);

/*
** ft_lst
*/

void			ft_del_content(void *content, size_t content_size);
void			ft_lst_push_back(t_list **alst, t_list *lnew);
void			ft_lstadd(t_list **alst, t_list *lnew);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);

/*
** ft_maths
*/

long int		ft_abs(int nb);
intmax_t		ft_power(int nb, int p);
intmax_t		ft_square(int nb);

/*
** ft_mem
*/

void			ft_bzero(void *s, size_t n);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);

/*
** ft_ntos
*/

char			*ft_dtoa(double value, int precision, char base);
char			*ft_intmaxtoa_base(intmax_t value, char base);
char			*ft_itoa(int n);
char			*ft_itoa_base(int value, int base);
char			*ft_ldtoa(long double value, int precision, char base);
char			*ft_llitoa_base(long long int value, char base);
char			*ft_uintmaxtoa_base(uintmax_t value, char base);
char			*ft_ullitoa_base(unsigned long long int value, char base);

/*
** ft_put
*/

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_puterror(char *disp);
void			ft_putperror(char *name, int iexit);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnstr_fd(unsigned char *str, unsigned int n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_puttab(int *tab, uintmax_t size, char *str);
void			ft_puttab_rev(int *tab, uintmax_t size, char *str);

/*
** ft_ston
*/

int				ft_atoi(const char *str);
int				ft_aatoi(char **line);
long int		ft_atol(const char *str);
long long int	ft_atoll(const char *str);

/*
** ft_str
*/

char			*ft_strcapitalize(char *str);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
void			ft_strdel(char **as);
char			*ft_strdup(const char *s1);
int				ft_strequ(char const *s1, char const *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strlowcase(char *str);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strndup(char *str, unsigned int cpy, unsigned int len);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
size_t			ft_strnlen(char *str, size_t len_max);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			*ft_strupcase(char *str);
int				ft_tolower(int c);
int				ft_toupper(int c);

#endif
