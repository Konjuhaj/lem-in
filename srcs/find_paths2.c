/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 18:50:53 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/25 19:19:12 by bkonjuha         ###   ########.fr       */
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
	t_edge *pair;

	i = -1;
	while (temp->edge[++i].next)
	{
		pair = temp->edge[i].pair;
		if (temp->edge[i].current == 0 && pair->current != 0)
			room = pair->next;
		else if (temp->edge[i].current == 0)
			continue ;
		room = temp->edge[i].next;
		if (room->visited != 2)
		{
			if(room->name != end)
			{
				temp->edge[i].current = 0;
				room->visited = 2;
			}
			ft_queueadd(queue, ft_queuenew(room, sizeof(*room), room->name), temp->name);
		}
		if (room->name == end)
			return(1);
	}
	return (0);
}

void		find_paths2(t_room *room, char *end, t_farm *farm)
{
	t_queue	*queue;
	t_queue *base;
	t_room	*temp;

	queue = ft_queuenew(room, sizeof(*room), room->name);
	base = queue;
	temp = room;
	while (!(ft_strequ(queue->id, end)))
	{
		if ((add_rooms(&queue, temp, end)))
			store_path(base, room->name, farm);
		if(!(next_room(&temp, &queue))) // dead-end paths need to freed
			break ;
	}
}
