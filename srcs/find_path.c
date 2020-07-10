/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 17:51:09 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/10 09:49:36 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

/*
** Move to the next room and get the T_room node out of q_queue
*/

static void next_room(t_room **temp, t_queue **queue)
{
	*queue = (*queue)->next;
	*temp = (*queue)->content;
}

static int add_rooms(t_queue **queue, t_room *temp, char *end)
{
	int		i;
	t_room	*room;

	i = -1;
	while (temp->pipe[++i])
	{
		room = temp->pipe[i];
		if (room->visited == 0)
		{
			ft_queueadd(queue, ft_queuenew(room, sizeof(*room), room->name), temp->name);
		}
		if (room->name == end)
			return(1);
	}
	return (0);
}

static int add_rooms_rev(t_queue **queue, t_room *temp, char *end)
{
	int		i;
	t_room	*room;

	i = 0;
	while (temp->pipe[i])
		i++;
	while (--i > -1)
	{
		room = temp->pipe[i];
		if (room->visited == 0)
		{
			ft_queueadd(queue, ft_queuenew(room, sizeof(*room), room->name), temp->name);
		}
		if (room->name == end)
			return(1);
		}
	return (0);
}

void		store_path(t_queue *queue, char *first, t_farm *farm)
{
	int		i;
	t_queue	*path;

	i = 1;
	path = ft_dequeue(&queue);
	path->distance = 0;
	while (path->id != first)
	{
		ft_queueaddfront(&path, ft_queuefind(&queue, path->called_by));
		path->distance = i++;
	}
	//print_queue_id(path);
	save_path(path, farm);
}

void		find_paths(t_room *room, char *end, char *id, t_farm *farm)
{
	t_queue	*queue;
	t_queue *base;
	t_room	*temp;

	queue = ft_queuenew(room, sizeof(*room), room->name);
	base = queue;
	temp = room;
	while (!ft_strequ(queue->id, end))
	{
		temp->visited = 1;
		if (ft_strequ(id, "forward"))
		{
			if (add_rooms(&queue, temp, end) == 1)
				store_path(base, room->name, farm);
		}
		else if (ft_strequ(id, "reverse"))
		{
			if (add_rooms_rev(&queue, temp, end) == 1)
				store_path(base, room->name, farm);
		}
		next_room(&temp, &queue);
		//print_queue_id(base);
	}
	//store_path(base, room->name, farm);
}
