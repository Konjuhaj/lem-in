/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 19:55:18 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/30 21:41:59 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int		has_unvisited_neigbour(t_room *room, int i)
{
	t_room *temp;
	int		original;

	original = i;
	while (room->edge[i].next)
	{
		temp = room->edge[i].next;
		if (!temp->path)
			return (i);
		i++;
	}
	return (original);
}

static int		add_rooms(t_queue *queue, t_room *end)
{
	int		i;
	t_room	*room;
	t_room	*neigbor;

	i = -1;
	room = queue->content;
	while (room->edge[++i].next)
	{
		if (room->edge[i].current == 0)
			continue ;
		i = has_unvisited_neigbour(room, i);
		neigbor = room->edge[i].next;
		if (!neigbor->visited)
		{
			room->edge[i].current = 0;
			if (neigbor != end)
				neigbor->visited = 2;
			ft_queueadd(&queue, ft_queuenew(neigbor, sizeof(neigbor), neigbor->name), room->name);
		}
		if (neigbor == end)
			return (1);
	}
	return (0);
}

static void mark_path(t_queue *queue)
{
	t_queue *temp;
	t_room *room;

	temp = queue;
	while (temp->next)
		temp = temp->next;
	while (temp!= queue)
	{
		room = temp->content;
		room->path = 2;
		temp = ft_queuefind(&queue, temp->called_by);
	}
}

void	bfs(t_room *start, t_room *end)
{
	t_queue *queue;
	t_queue *base;

	queue = ft_queuenew(start, sizeof(start), start->name);
	base = queue;
	start->visited = 2;
	while (!(add_rooms(queue, end)))
	{
		if (!queue->next)
			break ;
		queue = queue->next;
	}
	mark_path(base);
}
