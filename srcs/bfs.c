/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 19:55:18 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/23 20:37:50 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	has_unvisited_neigbour(t_room *room, int i)
{
	t_room	*temp;
	int		original;

	original = i;
	while (room->edge[i].next)
	{
		temp = room->edge[i].next;
		if (!temp->path && !temp->visited)
			return (i);
		i++;
	}
	return (original);
}

static int	add_rooms(t_queue *queue, t_room *end)
{
	int		i;
	t_room	*room;
	t_room	*neigbor;

	i = -1;
	room = queue->content;
	while (room->edge[++i].next)
	{
		neigbor = room->edge[i].next;
		if (room->edge[i].current == 0)
			continue ;
		if (room->edge[i].next != end && neigbor->path)
			i = has_unvisited_neigbour(room, i);
		neigbor = room->edge[i].next;
		if (!neigbor->visited)
		{
			if (neigbor != end)
				neigbor->visited = VISITED;
			ft_queueadd(&queue,
			ft_queuenew(neigbor, sizeof(neigbor), neigbor->name), room->name);
		}
		if (neigbor == end)
			return (1);
	}
	return (0);
}

static void	mark_current(t_room *from, t_room *to)
{
	int i;

	i = 0;
	while (from->edge[i].next != to)
		i++;
	from->edge[i].current = 0;
}

static void	mark_path(t_queue *queue)
{
	t_queue	*temp;
	t_queue *temp2;
	t_room	*room;

	temp = queue;
	while (temp->next)
		temp = temp->next;
	room = temp->content;
	room->path = 2;
	while (temp->id != queue->id)
	{
		temp2 = ft_queuefind(&queue, temp->called_by);
		mark_current(temp2->content, temp->content);
		temp = temp2;
		room = temp->content;
		room->path = 2;
	}
}

int			bfs(t_room *start, t_room *end)
{
	t_queue *queue;
	t_queue *base;

	queue = ft_queuenew(start, sizeof(start), start->name);
	base = queue;
	start->visited = 2;
	while (!(add_rooms(queue, end)))
	{
		if (!queue->next)
		{
			ft_free_queue(base);
			return (0);
		}
		queue = queue->next;
	}
	if (queue->content != start)
		mark_path(base);
	ft_free_queue(base);
	return (1);
}
