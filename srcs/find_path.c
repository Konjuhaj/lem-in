/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 17:51:09 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/05/23 20:53:33 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void next_room(t_room **room, t_queue **queue)
{
	*queue = (*queue)->next;
	*room = (*queue)->content;
}

static void add_room(t_queue *queue, t_room *temp)
{
	int		i;
	t_room	*room;

	i = -1;
	while (temp->pipe[++i])
	{
		room = temp->pipe[i];
		ft_printf("has %s been visited %d\n", room->name, room->visited);
		if (room->visited != 1)
		{
			ft_queueadd(&queue, ft_queuenew(room, sizeof(*room), room->name), temp->name, room->name);
		}
	}
}

void		store_path(t_queue *queue, char *last, char *first)// WOP
{
	t_list *path;
	t_queue *temp;

	temp = queue;
	while(temp->id != last)
		temp = temp->next;
	path = ft_lstnew(queue->id, sizeof(queue->id));
	while(temp->id != first)
	{
	}

}

void		find_paths(t_room *room, char *end)
{
	t_queue	*queue;
	t_room	*temp;
	int		stopper = 0;

	queue = ft_queuenew(room, sizeof(*room), room->name);
	temp = room;
	while (!ft_strequ(temp->name, end))
	{
		temp->visited = 1;
		add_room(queue, temp);
		next_room(&temp, &queue);
	}
	store_path(queue, temp->name, end);
}
