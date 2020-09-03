/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 09:07:20 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/09/03 14:52:42 by bkonjuha         ###   ########.fr       */
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
	if (!ft_isint(atol(s[1])) || !ft_isint(atol(s[2])))
		ft_errno("Coordinates out of bound", NULL);
}

char	**validate_instructions(char **s)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (s[j][0] == '#')
		j++;
	if(s[j][0] == '+')
		i++;
	while (s[j][++i])
		if (!ft_isdigit(s[j][i]))
			ft_errno("Special Character found in ants", NULL);
	if (!ft_isdigit(s[j][0]) && s[j][0] != '+')
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

void	validate_lines(char *s)
{
	int i;

	i = -1;
	if (s)
	{
		while (s[++i])
		{
			if ((s[i] == '\n' && s[i - 1] == '\n') || s[0] == '\n')
				ft_errno("Empty line found", NULL);
		}
	}
	else
		ft_errno("Empty file found", NULL);
	if (i < 6)
		ft_errno("Insufficient information", NULL);
}

void	check_duplicates(char **s)
{
	int end;
	int start;
	int i;

	end = 0;
	start = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i][0] == '#' && s[i][1] == '#')
		{
			end += ft_strequ(s[i], "##end") ? 1 : 0;
			start += ft_strequ(s[i], "##start") ? 1 : 0;
		}
	}
	if (end != 1 || start != 1)
		ft_errno("Incorrect amount of mandatory commands", NULL);
}
