/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 23:23:43 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/08 14:10:43 by bkonjuha         ###   ########.fr       */
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

static void	pathfinder(t_farm *farm)
{
	int		temp; //testing
	int		i;
	int		count;
	char	*direction;

	direction = "forward";
	temp = -1;
	i = -1;
	count = 0;
	while (farm->source->pipe[++temp])
	{
		farm->source->visited = 2;
		find_paths(farm->source->pipe[temp], farm->sink->name, direction, farm);
		int i = -1;
		while (farm->rooms[++i])
		{
			farm->rooms[i]->visited = 0;
		}
		if (!farm->source->pipe[temp + 1])
		{
			direction = "reverse";
			count++;
			temp = -1;
			if (count == 2)
				break ;
		}
	}
}

int			main(int ac, char **av)
{
	char	**file;
	t_farm	farm;

	if (ac == 2)
	{
		file = get_rooms(av[1]);
		farm.ants = ft_atoi(av[1]);
		connect_rooms(file, &farm, read_rooms(file, &farm));
		if(!(farm.paths = (t_combinations *)malloc(sizeof(t_combinations))))
			ft_errno();
		farm.paths->set = NULL;
		//pathfinder(&farm);
	}
	system("leaks lem-in");
	return (0);
}
