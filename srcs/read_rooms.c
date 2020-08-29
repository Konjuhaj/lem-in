/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 12:07:38 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/29 13:20:00 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	count_rooms(char **s, t_farm *farm)
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
	farm->count = count;
	return (count);
}

int			read_rooms(char **s, t_farm *farm)
{
	int		i;
	int		j;
	char	**temp;

	i = 0;
	farm->rooms = init_all_rooms(count_rooms(s, farm));
	j = 0;
	check_duplicates(s);
	while (s[++i])
	{
		if (is_command_or_comment(s[i]))
			continue ;
		if ((ft_strchr(s[i], '-')))
			break ;
		farm->rooms[j] = init_room(farm->count);
		if (ft_strequ(s[i], "##start") && i++)
			farm->source = farm->rooms[j];
		if (ft_strequ(s[i], "##end") && i++)
			farm->sink = farm->rooms[j];
		validate_rooms((temp = ft_strsplit(s[i], ' ')));
		farm->rooms[j++]->name = ft_strdup(temp[0]);
		ft_strstrdel(&(temp));
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
	while (from->edge[i].next != NULL && from->edge[i].next != to)
		i++;
	if (from->edge[i].next == to)
		ft_errno("duplicate connection", NULL);
	from->edge[i].next = to;
	while (to->edge[j].next != NULL && to->edge[j].next != from)
		j++;
	if (to->edge[j].next == from)
		ft_errno("duplicate connection", NULL);
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
	check_path_to_source(farm);
}
