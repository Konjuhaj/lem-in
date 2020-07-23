/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 17:51:09 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/23 14:58:13 by bkonjuha         ###   ########.fr       */
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
	t_edge	*pair;

	i = -1;
	while (temp->edge[++i].next)
	{
		if (temp->edge[i].current <= 0)
			continue ;
		temp->edge[i].current = -1;
		pair = temp->edge[i].pair;
		pair->current = 1;
		room = temp->edge[i].next;
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
	while (temp->edge[i].next)
		i++;
	while (--i > -1)
	{
		room = temp->edge[i].next;
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
	// print_queue_id(path);
	save_path(path, farm);
}

int		test(void)
{
	return (1);
}

void		find_paths(t_room *room, char *end, char *id, t_farm *farm)
{
	t_queue	*queue;
	t_queue *base;
	t_room	*temp;
	int		ret;
	int		count;

	queue = ft_queuenew(room, sizeof(*room), room->name);
	base = queue;
	temp = room;
	count = 0;
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
		if(!(ret = next_room(&temp, &queue))) // dead-end paths need to freed
			break ;
	}
}
