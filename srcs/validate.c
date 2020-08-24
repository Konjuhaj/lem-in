/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 09:07:20 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/24 16:04:02 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	are_numbers(char *s)
{
	int i;
	int fine;

	i = -1;
	fine = 0;
	while (s[++i])
	{
		fine = ft_isdigit(s[i]);
		if ((s[i] == '-' || s[i] == '+') && i == 0)
			fine = ft_isdigit(s[i + 1]);
		if (fine == 0)
			ft_errno("Invalid coordinates found", NULL);
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
		ft_errno("Wrong number of coordinated found", NULL);
}

char	**validate_instructions(char **s)
{
	int		i;

	i = -1;
	while (s[0][++i])
		if (!ft_isdigit(s[0][i]))
			ft_errno("Special Character found in ants", NULL);
	if (s[0][0] == '0' || !ft_isdigit(s[0][0]))
		ft_errno("Missing ants", NULL);
	i = -1;
	while (s[++i])
	{
		if (s[i][0] == 'L' || (i > 0 &&
		((ft_strequ(s[i], "##start") && ft_strequ(s[i - 1], "##end"))
		|| (ft_strequ(s[i], "##end") && ft_strequ(s[i - 1], "##start")))))
			ft_errno("Invalid Commands found", NULL);
	}
	return (s);
}

void		validate_lines(char *s)
{
	int i;

	i = -1;
	if (s)
	{
		while (s[++i])
		{
			if ((s[i] == '\n' && s[i -1] == '\n') || s[0] == '\n')
				ft_errno("Empty line found", NULL);
		}
	}
	else
		ft_errno("Empty file found", NULL);
	if (i < 6)
		ft_errno("Insufficient information", NULL);
	else if (s[i -1] != '\n')
		ft_errno("Missing new line at the end", NULL);
}
