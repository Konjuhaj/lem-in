/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 16:15:44 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/04/12 13:31:58 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	print_values(t_farm *farm)
{
	int i;

	i = -1;
	while (farm->rooms[++i] != NULL)
	{
		ft_printf("room %s, distance %i, length %d, visited %d \n", farm->rooms[i]->name, farm->rooms[i]->distance, farm->rooms[i]->length, farm->rooms[i]->visited);
	}
}
