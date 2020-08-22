/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 23:23:43 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/20 23:22:54 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static char	**get_rooms(char *av)
{
	int 	fd;
	char	*line;

	fd = open(av, O_RDONLY);
	line = ft_read_file(fd);
	// ft_putendl(line);
	return (ft_strsplit(line, '\n'));
}

static void	reset_unused_edges(t_farm *farm)
{
	int i;

	i = -1;
	while(farm->rooms[++i])
		farm->rooms[i]->visited = 0;
	i = -1;
}

static void	pathfinder(t_farm *farm)
{
		int i;

		i = -1;
		farm->source->visited = 2;
		bfs(farm->source, farm->sink, farm);
		reset_unused_edges(farm);
		reconstruct_path(farm->sink, farm->source, farm);
		reset_unused_edges(farm);
		while (++i < 40)
		{
			farm->source->visited = 2;
			bfs(farm->source, farm->sink, farm);
			reset_unused_edges(farm);
			reconstruct_path(farm->sink, farm->source, farm);
			reset_unused_edges(farm);
		}
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
	//ystem("leaks lem-in");
	return (0);
}
