/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 17:51:09 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/04 17:29:00 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void next_room(t_room **room, t_queue **queue)
{
	*queue = (*queue)->next;
	*room = (*queue)->content;
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
			room->visited = 1;
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
			room->visited = 1;
		}
		if (room->name == end)
			return(1);
	}
	return (0);
}

void		store_path(t_queue *queue, char *first)
{
	t_queue *path;

	path = ft_dequeue(&queue);
	while (path->id != first)
	{
		ft_queueaddfront(&path, ft_queuefind(&queue, path->called_by));
	}
	save_path(path);
}

void		find_paths(t_room *room, char *end, char *id)
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
				store_path(base, room->name);
		}
		else if (ft_strequ(id, "reverse"))
		{
			if (add_rooms_rev(&queue, temp, end) == 1)
				break ;
		}
		next_room(&temp, &queue);
	}
	//store_path(base, room->name);
}
