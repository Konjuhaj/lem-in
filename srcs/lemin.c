/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 23:23:43 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/04 18:39:51 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		main(int ac, char **av)
{
	char	**file;
	char	*line;
	int 	fd;
	int		temp; //testing
	t_farm	farm;

	if (ac == 2)
	{
		temp = -1;
		fd = open(av[1], O_RDONLY);
		line = ft_read_file(fd);
		file = ft_strsplit(line, '\n');
		farm.ants = ft_atoi(file[0]);
		connect_rooms(file, &farm, read_rooms(file, &farm));
		if(!(farm.paths = (t_combinations *)malloc(sizeof(t_combinations))))
			ft_errno();
		farm.paths->set = NULL;
		while (farm.source->pipe[++temp])
		{
			farm.source->visited = 2;
			find_paths(farm.source->pipe[temp], farm.sink->name, "forward", &farm);
			int i = -1;
			while (farm.rooms[++i])
			{
				farm.rooms[i]->visited = 0;
			}
		}
		temp = -1;
		while (farm.source->pipe[++temp])
		{
			find_paths(farm.source->pipe[temp], farm.sink->name, "reverse", &farm);
			int i = -1;
			while (farm.rooms[++i])
			{
				farm.rooms[i]->visited = 0;
			}
			farm.source->visited = 2;
		}
	}
	//system("leaks lem-in");
	return (0);
}
