/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 23:23:43 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/24 17:53:56 by bkonjuha         ###   ########.fr       */
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
	int		count;
	char	*direction;

	direction = "forward";
	temp = -1;
	count = 0;
	farm->source->visited = 2;
	// find_paths(farm->source, farm->sink->name, direction, farm);
	while (farm->source->edge[++temp].next)
	{
		farm->source->visited = 2;
		find_paths(farm->source->edge[temp].next, farm->sink->name, direction, farm);
		int i = -1;
		while (farm->rooms[++i])
		{
			int j = -1;
			while (farm->rooms[i]->edge[++j].next)
				farm->rooms[i]->edge[j].current = 1;
		}
		if (!farm->source->edge[temp + 1].next)
		{
			direction = "reverse";
			count++;
			temp = -1;
			if (count == 2)
				break ;
		}
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
