/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:17:35 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/09/03 11:50:07 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		is_command_or_comment(char *s)
{
	if (s[0] == '#' && s[1] != '#')
		return (1);
	else if (s[0] == '#' && s[1] == '#' &&
			!ft_strequ(s, "##start") && !ft_strequ(s, "##end"))
		return (1);
	return (0);
}

void	duplicate_room(t_farm *farm)
{
	int i;
	int j;

	i = 0;
	while (farm->rooms[i])
		i++;
	i--;
	j = i;
	while (i-- > 0)
	{
		if (ft_strequ(farm->rooms[j]->name, farm->rooms[i]->name))
			ft_errno("Duplicate rooms", NULL);
	}
}
