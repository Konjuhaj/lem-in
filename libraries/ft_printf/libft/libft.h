/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 08:13:08 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/03/29 12:13:43 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 32
# define MAX_FD 10240
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *str);

char				*ft_strdup(const char *str);

char				*ft_strcpy(char *dest, const char *src);

void				ft_putchar(char c);

void				ft_putstr(char const *str);

int					ft_atoi(const char *str);

char				*ft_strncpy(char *dest, const char *src, size_t len);

int					ft_strcmp(const char *s1, const char *s2);

int					ft_strncmp(const char *s1, const char *s2, size_t len);

char				*ft_strstr(const char *haystack, const char *needle);

char				*ft_strnstr(const char *haystack,
					const char *needle, size_t len);

char				*ft_strcat(char *dest, const char *src);

char				*ft_strncat(char *dest, const char *src, size_t len);

size_t				ft_strlcat(char *dest, const char *src, size_t len);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

int					ft_toupper(int c);

int					ft_tolower(int c);

char				*ft_strchr(const char *haystack, int n);

char				*ft_strrchr(const char *haystack, int n);

void				*ft_memset(void *str, int c, size_t len);

void				ft_bzero(void *str, size_t len);

void				*ft_memalloc(size_t len);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

void				*ft_memchr(const void *str, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_memcpy(void *dst, const void *src, size_t n);

void				*ft_memmove(void *dst, const void *src, size_t n);

void				*ft_memset(void *str, int c, size_t len);

void				ft_memdel(void **ap);

char				*ft_strnew(size_t size);

void				ft_strdel(char **as);

void				ft_strclr(char *s);

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

void				ft_striter(char *s, void (*f)(char *));

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s);

int					ft_strequ(char const *s1, char const *s2);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				**ft_strsplit(char const *s, char c);

char				*ft_itoa(long long n);

void				ft_putendl(char const *s);

void				ft_putnbr(int n);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char const *s, int fd);

void				ft_putendl_fd(char const *s, int fd);

void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);

void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				ft_lstputstr(t_list *lst);

int					ft_isspace(int c);

int					ft_wlen(char const *s, char c);

int					ft_wcount(char const *s, char c);

void				ft_printbit(int n);

t_list				*ft_lstsplit(char *s, char c);

int					ft_isblank(int c);

int					ft_iscntrl(int c);

int					ft_isxdigit(int c);

void				ft_putnbr_base(long long num, int base, int id);

char				*ft_itoa_base(long long num, int base);

int					ncount(long long n);

void				ft_capitalize(char *s);

char				*ft_uitoa_base(unsigned long long nb, int base);

int					ncount_base(long long n, int base);

int					ft_abs(int num);

char				*ft_strjoin2(char const *s1,
					char const *s2, char const *s3);

int					get_next_line(const int fd, char **line);

long				ft_atol(const char *str);

void				ft_strstrdel(char ***s);

char				*ft_read_file(int fd);

int					ft_rowlen(char **s);

char				*ft_strcpy_until(char *s, char c);

#endif
