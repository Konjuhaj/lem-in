/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 12:07:38 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/10 09:50:17 by bkonjuha         ###   ########.fr       */
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
		while (s[i][0] == '#'&& s[i][1] != '#')
			i++;
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
		farm->rooms[j++]->visited = 0;
	}
	farm->rooms[j] = NULL;
	return (i);
}

static void	connect_bothways(t_room *from, t_room *to)
{
	int i;

	i = 0;
	while (from->pipe[i] != NULL)
		i++;
	from->pipe[i] = to;
	while (to->pipe[i] != NULL)
		i++;
	to->pipe[i] = from;
}

void	connect_rooms(char **s, t_farm *farm, int i)
{
	char *from;
	char *to;
	int	src_room;
	int	dst_room;

	while(s[i])
	{
		if (s[i][0] == '#' && i++)
			continue ;
		src_room = 0;
		dst_room = 0;
		from = ft_strsub_until(s[i], '-');
		while (!(ft_strequ(farm->rooms[src_room]->name, from)))
			src_room++;
		to = ft_strsub_until(ft_strchr(s[i], '-') + 1, 0);
		while (!(ft_strequ(farm->rooms[dst_room]->name, to)))
			dst_room++;
		ft_strdel(&to);
		ft_strdel(&from);
		connect_bothways(farm->rooms[src_room], farm->rooms[dst_room]);
		i++;
	}
}
