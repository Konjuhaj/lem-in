/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 09:07:20 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/24 11:04:14 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	are_numbers(char *s)
{
	int i;
	int fine;

	i = 0;
	fine = 0;
	while (s[++i])
	{
		fine = ft_isdigit(s[i]);
		if ((s[i] == '-' || s[i] == '+') && i == 0)
			fine = ft_isdigit(s[i + 1]);
		if (fine == 0)
			ft_errno();
	}
}

void	validate_rooms(char **s)
{
	int	i;

	i = 0;
	while (s[++i])
	{
		are_numbers(s[i]);
	}
	if (i != 3)
		ft_errno();
}

char	**validate_instructions(char **s)
{
	int		i;

	i = -1;
	while (s[0][++i])
		if (!ft_isdigit(s[0][i]))
			ft_errno();
	i = -1;
	while (s[++i])
	{
		if (s[i][0] == 'L' || (i > 0 &&
		((ft_strequ(s[i], "##start") && ft_strequ(s[i - 1], "##end"))
		|| (ft_strequ(s[i], "##end") && ft_strequ(s[i - 1], "##start")))))
			ft_errno();
		else if (ft_strchr(s[i], ' ') && ft_strchr(s[i], '-'))
			ft_errno();
	}
	return (s);
}

void		validate_lines(char *s)
{
	int i;

	i = 0;
	while (s[++i])
	{
		if (s[i] == '\n' && s[i -1] == '\n')
			ft_errno();
	}
	if (i < 6)
		ft_errno();
}
