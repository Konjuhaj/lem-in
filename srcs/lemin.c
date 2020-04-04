/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 23:23:43 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/04/04 19:21:35 by bkonjuha         ###   ########.fr       */
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

int		read_rooms(char **s, t_farm *farm)
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
	char *temp;
	int	j;
	int	k;
	int l;

	while(s[i])
	{
		j = 0;
		k = 0;
		l = 0;
		temp = ft_strcpy_until(s[i], '-');
		while (!(ft_strequ(farm->rooms[j]->name, temp)))
			j++;
		ft_strdel(&temp);
		temp = ft_strcpy_until(ft_strchr(s[i], '-') + 1, 0);
		while (!(ft_strequ(farm->rooms[k]->name, temp)))
			k++;
		ft_strdel(&temp);
		while (farm->rooms[j]->pipe[l] != NULL)
			l++;
		farm->rooms[j]->pipe[l] = farm->rooms[k];
		l = 0;
		while (farm->rooms[k]->pipe[l] != NULL)
			l++;
		farm->rooms[k]->pipe[l] = farm->rooms[j];
		i++;
	}
}

int		main(int ac, char **av)
{
	char	**file;
	char	*line;
	int 	fd;
	int		limit;
	t_farm	*farm;

	if (ac == 2)
	{
		limit = 0;
		if (!(farm = (t_farm *)malloc(sizeof(t_farm))))
			ft_errno();
		fd = open(av[1], O_RDONLY);
		line = ft_read_file(fd);
		file = ft_strsplit(line, '\n');
		farm->ants = ft_atoi(file[0]);
		if(!(farm->rooms = (t_room **)malloc(sizeof(t_room *) * ft_rowlen(av))))
			ft_errno();
		connect_rooms(file, farm, read_rooms(file, farm));
		while (find_paths(&farm->source,&farm->sink, limit, 0) != 3)
			limit++;
	}
	// s(ystem("leaks a)->out");
	return (0);
}
