/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 17:51:09 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/06/05 09:43:29 by bkonjuha         ###   ########.fr       */
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
		if (room->visited != 1)
		{
			ft_queueadd(queue, ft_queuenew(room, sizeof(*room), room->name), temp->name);
		}
		if (room->name == end)
			return(1);
	}
	return (0);
}

void		print_queue_id(t_queue **queue)
{
	t_queue *temp;

	temp = *queue;
	while (temp)
	{
		ft_printf("%s -> ", temp->id);
		temp = temp->next;
	}
	ft_putstr("\n");
}

void		store_path(t_queue *queue, char *first)// WOP
{
	t_queue *path;

	path = ft_dequeue(&queue);
	while (path->id != first)
	{
		ft_queueaddfront(&path, ft_queuefind(&queue, path->called_by));
	}
	print_queue_id(&queue);
}

void		find_paths(t_room *room, char *end)
{
	t_queue	*queue;
	t_queue *base;
	t_room	*temp;

	queue = ft_queuenew(room, sizeof(*room), room->name);
	base = queue;
	temp = room;
	while (!ft_strequ(temp->name, end))
	{
		temp->visited = 1;
		if (add_rooms(&queue, temp, end) == 1)
			break ;
		next_room(&temp, &queue);
	}
	store_path(base, temp->name);
}
