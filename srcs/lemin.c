/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 23:23:43 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/25 19:24:32 by bkonjuha         ###   ########.fr       */
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

static void	pathfinder(t_farm *farm)
{
	int		i; //testing

	i = -1;
	while (farm->source->edge[++i].next)
	{
		farm->source->path = 2;
		farm->source->visited = 2;
		find_shortest(farm->source->edge[i].next, farm->sink->name, farm);
		reset_unused_edges(farm);
		farm->source->visited = 2;
		find_paths(farm->source->edge[i].next, farm->sink->name, farm);
		reset_unused_edges(farm);
		farm->source->visited = 2;
		find_paths2(farm->source->edge[i].next, farm->sink->name, farm);
	}
}

/*
** Room cleaning. Causes leaks. Maybe not necassary.
*/
// static void	clean_up_rooms(t_farm *farm)
// {
// 	t_queue *temp;
// 	t_queue *base;

// 	base = farm->paths->set;
// 	while (base)
// 	{
// 		temp = base;
// 		while (temp->content != farm->sink)
// 			temp = temp->next;
// 		temp->next = NULL;
// 		base = base->parralel;
// 	}
// }

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
		//clean_up_rooms(&farm);
		combinations(&farm);
		send_ants(&farm);
	}
	//print_sets(farm.paths);
	//system("leaks lem-in");
	return (0);
}
