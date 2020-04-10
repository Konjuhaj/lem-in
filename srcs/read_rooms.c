/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 12:07:38 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/04/10 15:42:57 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void	malloc_rooms(t_farm *farm)
{
	if (!(farm->source = (t_room *)malloc(sizeof(t_room))) ||
		!(farm->sink = (t_room *)malloc(sizeof(t_room))))
		ft_errno();
}

static void	set_rooms_to_null(t_farm *farm, int j)
{
	int i;
	int k;

	i = -1;
	while (++i < j)
	{
		k = -1;
		farm->rooms[i]->pipe = (void **)malloc(sizeof(void *) * j);
		while (++k < j)
			farm->rooms[i]->pipe[k] = NULL;
	}
}

int		readst_rooms(char **s, t_farm *farm)
{
	int i;

	int	j;

	i = 0;
	j = 0;
	malloc_rooms(farm);
	while(s[++i])
	{
		if (!(farm->rooms[j] = (t_room *)malloc(sizeof(t_room))))
			ft_errno();
		if((ft_strchr(s[i], '-')))
			break ;
		else if (ft_strequ(s[i], "##start") && i++)
			farm->source = farm->rooms[j];
		else if (ft_strequ(s[i], "##end") && i++)
			farm->sink = farm->rooms[j];
		if (s[i][0] != '#')
			farm->rooms[j++]->name = ft_strcpy_until(s[i], ' ');
		farm->rooms[j -1]->visited = 0;
		set_rooms_to_null(farm, j);
	}
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
		from_to = ft_strcpy_until(s[i], '-');
		while (!(ft_strequ(farm->rooms[src_room]->name, from_to)))
			src_room++;
		ft_strdel(&from_to);
		from_to = ft_strcpy_until(ft_strchr(s[i], '-') + 1, 0);
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
