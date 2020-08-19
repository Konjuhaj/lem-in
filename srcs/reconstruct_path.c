/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reconstruct_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 20:37:44 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/19 23:06:27 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	add_paths(t_queue *queue, t_room *source)
{
	int		i;
	t_room	*room;
	t_room	*neigbor;
	t_edge	*pair;

	i = -1;
	room = queue->content;
	while (room->edge[++i].next)
	{
		pair = room->edge[i].pair;
		if (room->edge[i].current == 0 || pair->current != 0)
			continue ;
		neigbor = room->edge[i].next;
		if (neigbor->path && !neigbor->visited)
		{
			if (neigbor != source)
				neigbor->visited = VISITED;
			ft_queueadd(&queue, ft_queuenew(neigbor, sizeof(neigbor), neigbor->name), room->name);
		}
		if (neigbor == source)
			return (1);
	}
	return (0);
}

void	reconstruct_path2(t_room *sink, t_room *source, t_farm *farm)
{
	t_queue *queue;
	t_queue *base;
	t_queue *temp;

	queue = ft_queuenew(sink, sizeof(sink), sink->name);
	base = queue;
	sink->visited = VISITED;
	while (queue)
	{
		if(add_paths(queue, source))
		{
			temp = store_path(base, sink->name, farm);
		}
		queue = queue->next;
	}
	ft_free_queue(base);
}

void	reconstruct_path(t_room *sink, t_room *source, t_farm *farm)
{
	int i;
	int j;

	i = -1;
	while (sink->edge[++i].next)
	{
		reconstruct_path2(sink->edge[i].next, source, farm);
		j = -1;
		while (farm->rooms[++j])
			farm->rooms[j]->visited = 0;
	}
}
