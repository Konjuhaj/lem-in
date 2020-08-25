/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:27:21 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/24 18:51:30 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define OCTAL 8
# define HEXAL 16
# define DECIMAL 10
# define BINARY 2
# define NUMBER 1
# define TEXT 2
# define YELLOW "\033[1;33m"
# define RESET "\033[0m"
# define RED "\033[1;31m"
# define GREEN "\033[0;32m"
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct	s_container
{
	char		*buffer;
	int			id;
	char		filler;
}				t_container;

typedef	struct	s_data
{
	char		hash;
	int			ret;
	int			i;
	t_container container;
	va_list		arg;
	int			size;
	int			precision;
	int			length;
	char		sign;
	char		type;
	int			allign;
}				t_data;

int				ft_printf(const char *format, ...);

int				is_type(const char *s, t_data *data);

int				is_flag(const char *c, t_data *data);

int				is_width(const char *s, t_data *data);

int				is_precision(const char *s, t_data *data);

int				is_legth(const char *s, t_data *data);

void			x_flag(t_data *data);

void			o_flag(t_data *data);

void			d_flag(t_data *data);

void			c_flag(t_data *data);

void			s_flag(t_data *data);

void			percent_flag(t_data *data);

void			fill_buffer(char *c, t_data *data);

char			*dot_flag(char *c, t_data *data);

char			*sign_flag(t_data *data, char *temp);

int				create_buffer(const char *s, t_data *data);

char			*update_buffer(char *new);

void			ft_fill(char *temp, t_data *data);

void			p_flag(t_data *data);

int				ft_default(int i);

void			typecast(t_data *data, long long *num);

void			u_typecast(t_data *data, unsigned long *bignum);

void			f_flag(t_data *data);

void			move_right(t_data *data, char sign);

double			round_up(double num, int prec);

long double		l_round_up(long double num, int prec);

char			*ft_f_itoa(double num, int prec);

char			*ft_lf_itoa(long double num, int prec);

int				dot_validator(t_data *data, char **c, int *prec);

char			*hash_flag(char *s, t_data *data);

void			add_buffer_postfix(t_data *data, char *postfix);

void			add_buffer_prefix(char *prefix, t_data *data);

void			number_hub(t_data *data, char *temp);

void			b_flag(t_data *data);

void			capital_b_flag(t_data *data);

void			t_flag(t_data *data);

void			capital_t_flag(t_data *data);

void			capital_s_flag(t_data *data);

#endif
