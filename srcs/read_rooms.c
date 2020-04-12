/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 12:07:38 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/04/12 14:00:22 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

 static int	count_rooms(char **s)
 {
	int i;
	int count;

	count = 0;
	i = 0;
	while (s[++i])
	{
		if (s[i][0] != '#' && s[i][0] != 'L')
			count++;
	}
	return (count);
 }

static void	set_rooms_to_null(void **pipe, int limit)
{
	int i;

	i = -1;
	while (++i < limit)
		pipe[i] = NULL;
}

int		read_rooms(char **s, t_farm *farm)
{
	int i;
	int	j;
	int rooms;

	i = 0;
	rooms = count_rooms(s);
	farm->rooms = malloc(sizeof(*farm->rooms) * rooms);
	j = 0;
	while(s[++i])
	{
		if((ft_strchr(s[i], '-')))
			break ;
		if (!(farm->rooms[j] = (t_room *)malloc(sizeof(t_room))))
			ft_errno();
		farm->rooms[j]->pipe = (void **)malloc(sizeof(void *) * rooms);
		set_rooms_to_null(farm->rooms[j]->pipe, rooms);
		if (ft_strequ(s[i], "##start") && i++)
			farm->source = farm->rooms[j];
		if (ft_strequ(s[i], "##end") && i++)
			farm->sink = farm->rooms[j];
		farm->rooms[j]->name = ft_strsub_until(s[i], ' ');
		farm->rooms[j]->visited = 0;
		farm->rooms[j++]->length = 0;
	}
	farm->rooms[j] = NULL;
	return (i);
}

void	connect_rooms(char **s, t_farm *farm, int i)
{
	char *from_to;
	int	src_room;
	int	dst_room;
	int l;

	while(s[i])
	{
		src_room = 0;
		dst_room = 0;
		l = 0;
		from_to = ft_strsub_until(s[i], '-');
		while (!(ft_strequ(farm->rooms[src_room]->name, from_to)))
			src_room++;
		ft_strdel(&from_to);
		from_to = ft_strsub_until(ft_strchr(s[i], '-') + 1, 0);
		while (!(ft_strequ(farm->rooms[dst_room]->name, from_to)))
			dst_room++;
		ft_strdel(&from_to);
		while (farm->rooms[src_room]->pipe[l] != NULL)
			l++;
		farm->rooms[src_room]->pipe[l] = farm->rooms[dst_room];
		l = 0;
		while (farm->rooms[dst_room]->pipe[l] != NULL)
			l++;
		farm->rooms[dst_room]->pipe[l] = farm->rooms[src_room];
		i++;

	}
}
