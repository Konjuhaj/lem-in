/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 12:59:10 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/09/02 22:17:56 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void	send_all_ants_short(t_farm *farm)
{
	int ant;

	ant = 0;
	while (ant++ < farm->ants)
	{
		ft_printf("L%d-%s", ant, farm->sink->name);
		ant == farm->ants ? ft_putchar('\n') : ft_putchar(' ');
	}
}

void		check_path_to_source(t_farm *farm)
{
	int i;

	i = -1;
	while (farm->source->edge[++i].next)
	{
		if (farm->source->edge[i].next == farm->sink)
		{
			send_all_ants_short(farm);
			exit(0);
		}
	}
}
