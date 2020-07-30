/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reconstruct_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 09:45:43 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/30 09:50:24 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

/*
** Move to the next room and get the T_room node out of q_queue
*/

static int next_room(t_room **temp, t_queue **queue)
{
	if((*queue)->next)
	{
		*queue = (*queue)->next;
		*temp = (*queue)->content;
		return (1);
	}
	return (0);
}

static int add_rooms(t_queue **queue, t_room *temp, char *end)
{
	int		i;
	t_room	*room;

	i = -1;
	while (temp->edge[++i].next && temp->name != end)
	{
		if (temp->edge[i].current == 0)
			continue ;
		room = temp->edge[i].next;
		if (room->path && !room->visited)
		{
			temp->edge[i].current = 0;
			if(room->name != end)
			{
				room->visited = 2;
			}
			ft_queueadd(queue, ft_queuenew(room, sizeof(*room), room->name), temp->name);
		}
		if (room->name == end)
			return(1);
	}
	return (0);
}

void		reconstruct_path(t_room *room, char *end, t_farm *farm)
{
	t_queue	*queue;
	t_queue *base;
	t_room	*temp;

	queue = ft_queuenew(room, sizeof(*room), room->name);
	base = queue;
	temp = room;
	while (queue)
	{
		room->visited = 2;
		if ((add_rooms(&queue, temp, end)))
			store_path(base, room->name, farm);
		if(!(next_room(&temp, &queue))) // dead-end paths need to freed
			break ;
	}
}