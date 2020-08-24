/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 12:07:38 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/24 18:12:22 by bkonjuha         ###   ########.fr       */
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

int			read_rooms(char **s, t_farm *farm)
{
	int		i;
	int		j;
	int		rooms;
	char	**temp;

	i = 0;
	rooms = count_rooms(s);
	farm->rooms = init_all_rooms(rooms);
	j = 0;
	while (s[++i])
	{
		while (s[i][0] == '#' && s[i][1] != '#')
			i++;
		if ((ft_strchr(s[i], '-')))
			break ;
		farm->rooms[j] = init_room(rooms);
		if (ft_strequ(s[i], "##start") && i++)
			farm->source = farm->rooms[j];
		if (ft_strequ(s[i], "##end") && i++)
			farm->sink = farm->rooms[j];
		validate_rooms((temp = ft_strsplit(s[i], ' ')));
		farm->rooms[j++]->name = temp[0];
	}
	farm->rooms[j] = NULL;
	return (i);
}

static void	connect_bothways(t_room *from, t_room *to)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (from->edge[i].next != NULL)
		i++;
	from->edge[i].next = to;
	while (to->edge[j].next != NULL)
		j++;
	to->edge[j].next = from;
	to->edge[j].pair = &from->edge[i];
	from->edge[i].pair = &to->edge[j];
}

static int	find_room(char *name, t_farm *farm)
{
	int i;

	i = 0;
	while (farm->rooms[i] &&
		!(ft_strequ(farm->rooms[i]->name, name)))
	{
		i++;
	}
	if (!farm->rooms[i])
		ft_errno("Unabele to find room", NULL);
	return (i);
}

void		connect_rooms(char **s, t_farm *farm, int i)
{
	char	*from;
	char	*to;
	int		src_room;
	int		dst_room;

	if (!s[i])
		ft_errno("No connection", NULL);
	while (s[i])
	{
		if (s[i][0] == '#' && i++)
			continue ;
		src_room = 0;
		dst_room = 0;
		from = ft_strsub_until(s[i], '-');
		src_room = find_room(from, farm);
		to = ft_strsub_until(ft_strchr(s[i], '-') + 1, 0);
		dst_room = find_room(to, farm);
		ft_strdel(&to);
		ft_strdel(&from);
		connect_bothways(farm->rooms[src_room], farm->rooms[dst_room]);
		i++;
	}
}
