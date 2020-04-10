/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 16:15:44 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/04/10 16:20:29 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	print_values(t_farm *farm)
{
	int i;

	i = -1;
	while (farm->rooms[++i])
	{
		ft_printf("room %s, level %i, \n", farm->rooms[i]->name, farm->rooms[i]->level);
	}
}
