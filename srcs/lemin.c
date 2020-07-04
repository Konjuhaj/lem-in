/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 23:23:43 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/06/16 17:58:24 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	calculate_bottleneck(t_room *source)
{
	int i;

	i = 0;
	while (source->pipe[i])
		i++;
	return (i * i);
}

static void	print_set(t_combinations *paths)
{
	t_queue_set *set;
	t_queue 	*temp;

	set = paths->set;
	while (set->next)
	{
		temp = set->queue;
		while (temp->next)
		{
			ft_printf("%s ->", temp->id);
			temp = temp->next;
		}
		ft_printf("\n");
		set = set->next;
	}
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
		temp = -1;
		fd = open(av[1], O_RDONLY);
		line = ft_read_file(fd);
		file = ft_strsplit(line, '\n');
		farm.ants = ft_atoi(file[0]);
		connect_rooms(file, &farm, read_rooms(file, &farm));
		farm.bottleneck = calculate_bottleneck(farm.source);
		farm.paths = (t_combinations *)malloc(sizeof(t_combinations));
		mm_store_paths(&farm, NULL);
		while (farm.source->pipe[++temp])
		{
			farm.source->visited = 2;
			find_paths(farm.source->pipe[temp], farm.sink->name, "forward");
			int i = -1;
			while (farm.rooms[++i])
			{
				farm.rooms[i]->visited = 0;
			}
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
	print_set(farm.paths);
	//system("leaks lem-in");
	return (0);
}
