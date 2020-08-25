/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 19:54:18 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/24 17:58:48 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_option		*init_option(void)
{
	t_option *op;

	if (!(op = (t_option *)malloc(sizeof(t_option))))
		ft_errno("Failed to allocate memory", NULL);
	op->info = 0;
	op->paths = 0;
	op->error = 0;
	op->help = 0;
	return (op);
}

t_room			**init_all_rooms(int count)
{
	t_room	**rooms;
	int		i;

	i = -1;
	if (!(rooms = (t_room **)malloc(sizeof(t_room*) * count)))
		ft_errno("Failed to allocate memory", NULL);
	while (++i < count)
		rooms[i] = NULL;
	return (rooms);
}

t_room			*init_room(int edges)
{
	t_room	*room;
	int		i;

	i = -1;
	if (!(room = (t_room *)malloc(sizeof(t_room))))
		ft_errno("Failed to allocate memory", NULL);
	if (!(room->edge = (t_edge *)malloc(sizeof(t_edge) * edges)))
		ft_errno("Failed to allocate memory", NULL);
	room->name = NULL;
	room->path = 0;
	room->visited = 0;
	while (++i < edges)
	{
		room->edge[i].next = NULL;
		room->edge[i].pair = NULL;
		room->edge[i].current = 1;
	}
	return (room);
}

t_combinations	*init_comb(void)
{
	t_combinations *comb;

	if (!(comb = (t_combinations *)malloc(sizeof(t_combinations))))
		ft_errno("Failed to allocate memory", NULL);
	comb->next = NULL;
	comb->print = 0;
	comb->set = NULL;
	comb->using = NULL;
	return (comb);
}
