/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 23:23:43 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/13 19:59:07 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static char	**get_rooms(char *av)
{
	int 	fd;
	char	*line;

	fd = open(av, O_RDONLY);
	line = ft_read_file(fd);
	return (ft_strsplit(line, '\n'));
}

static void	reset_unused_edges(t_farm *farm)
{
	int i;
	int j;
	t_room *temp;
	t_edge *pair;

	i = -1;
	while(farm->rooms[++i])
	{
		farm->rooms[i]->visited = 0;
		if(farm->rooms[i]->path == 0)
		{
			temp = farm->rooms[i];
			j = -1;
			while(temp->edge[++j].next)
			{
				temp->edge[j].current = 1;
				pair = temp->edge[j].pair;
				pair->current = 1;
			}
		}
	}
}

// static void	reset_all_edges(t_farm * farm)
// {
// 	int i;
// 	int j;
// 	t_room *temp;

// 	i = -1;
// 	while(farm->rooms[++i])
// 	{
// 		farm->rooms[i]->visited = 0;
// 		temp = farm->rooms[i];
// 		j = -1;
// 		while(temp->edge[++j].next)
// 		{
// 			temp->edge[j].current = 1;
// 		}
// 	}
// }

static void	pathfinder(t_farm *farm)
{
		int i;

		i = -1;
		farm->source->path = 2;
		farm->source->visited = 2;
		bfs(farm->source, farm->sink, farm);
		reset_unused_edges(farm);
		reconstruct_path(farm->sink, farm->source, farm);
		reset_unused_edges(farm);
		while (++i < 50)
		{
			//ft_printf("\n ITARATION #%d\n", i);
			farm->source->path = 2;
			farm->source->visited = 2;
			bfs(farm->source, farm->sink, farm);
			reset_unused_edges(farm);
			reconstruct_path(farm->sink, farm->source, farm);
			reset_unused_edges(farm);
		}
		// exit(2);
}

int			main(int ac, char **av)
{
	char	**file;
	t_farm	farm;

	if (ac == 2)
	{
		file = get_rooms(av[1]);
		farm.ants = ft_atoi(file[0]);
		connect_rooms(file, &farm, read_rooms(file, &farm));
		if(!(farm.paths = (t_combinations *)malloc(sizeof(t_combinations))))
			ft_errno();
		farm.paths->set = NULL;
		pathfinder(&farm);
		combinations(&farm);
		send_ants(&farm);
	}
	//print_sets(farm.paths);
	//system("leaks lem-in");
	return (0);
}
