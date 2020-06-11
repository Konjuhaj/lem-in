/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 23:23:43 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/06/11 21:00:04 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void		print_queue_id(t_queue *queue)
{
	t_queue *temp;

	temp = queue;
	while (temp)
	{
		ft_printf("%s -> ", temp->id);
		temp = temp->next;
	}
	ft_putstr("\n");
}

void	print_paths(t_farm *farm)
{
	int i = -1;

	while(farm->paths->paths[++i])
		print_queue_id(farm->paths->paths[i]);

}

int		main(int ac, char **av)
{
	char	**file;
	char	*line;
	int 	fd;
	int		temp; //testing
	t_farm	farm;

	if (ac == 2)
	{
		path_constructor(&farm, NULL);
		temp = -1;
		fd = open(av[1], O_RDONLY);
		line = ft_read_file(fd);
		file = ft_strsplit(line, '\n');
		farm.ants = ft_atoi(file[0]);
		connect_rooms(file, &farm, read_rooms(file, &farm));
		farm.source->visited = 2;
		// find_paths(farm.source, farm.sink->name, "forward");
		while (farm.source->pipe[++temp])
		{
			find_paths(farm.source->pipe[temp], farm.sink->name, "forward");
			int i = -1;
			while (farm.rooms[++i])
			{
				farm.rooms[i]->visited = 0;
			}
			farm.source->visited = 2;
			ft_putchar('\n');
		}
		temp = -1;
		while (farm.source->pipe[++temp])
		{
			find_paths(farm.source->pipe[temp], farm.sink->name, "reverse");
			int i = -1;
			while (farm.rooms[++i])
			{
				farm.rooms[i]->visited = 0;
			}
			farm.source->visited = 2;
		}
	}
	print_paths(&farm);
	//system("leaks lem-in");
	return (0);
}
