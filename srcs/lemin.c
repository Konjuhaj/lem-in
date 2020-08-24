/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 23:23:43 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/24 18:03:34 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static char		**get_rooms(t_farm *farm)
{
	char	*line;
	char	**strstr;

	line = ft_read_file(STD_IN);
	validate_lines(line);
	farm->file = line;
	strstr = ft_strsplit(line, '\n');
	return (validate_instructions(strstr));
}

static void	reset_unused_edges(t_farm *farm)
{
	int i;

	i = -1;
	while (farm->rooms[++i])
		farm->rooms[i]->visited = 0;
}

static void		pathfinder(t_farm *farm)
{
	int i;

	i = -1;
	bfs(farm->source, farm->sink);
	reset_unused_edges(farm);
	reconstruct_path(farm->sink, farm->source, farm);
	reset_unused_edges(farm);
	while (bfs(farm->source, farm->sink))
	{
		reset_unused_edges(farm);
		reconstruct_path(farm->sink, farm->source, farm);
		reset_unused_edges(farm);
	}
	if (!farm->paths->set)
		ft_errno("No paths found", NULL);
}

static t_option	*parse(int ac, char **av)
{
	int			i;
	t_option	*op;

	i = 0;
	op = init_option();
	while (++i < ac)
	{
		if (ft_strequ(av[i], "-i") || ft_strequ(av[i], "--info"))
			op->info = 1;
		else if (ft_strequ(av[i], "-p") || ft_strequ(av[i], "--paths"))
			op->paths = 1;
		else if (ft_strequ(av[i], "-e") || ft_strequ(av[i], "--error"))
			op->error = 1;
		else if (!ft_strequ(av[i], "-i") && !ft_strequ(av[i], "--info")
			&& !ft_strequ(av[i], "-e") && !ft_strequ(av[i], "--error")
			&& !ft_strequ(av[i], "-p") && !ft_strequ(av[i], "--paths"))
			op->help = 1;
	}
	return (op);
}

int				main(int ac, char **av)
{
	char	**file;
	t_farm	farm;

	farm.op = parse(ac, av);
	if (farm.op->help)
	{
		ft_putstr("Usage:\n./lem-in [-e --error] [-i --info] ");
		ft_putendl("[-p --paths] < maps/demo_map");
		return (0);
	}
	else
	{
		ft_errno(NULL, farm.op);
		file = get_rooms(&farm);
		farm.ants = ft_atoi(file[0]);
		connect_rooms(file, &farm, read_rooms(file, &farm));
		farm.paths = init_comb();
		farm.paths->set = NULL;
		pathfinder(&farm);
		combinations(&farm);
		print_info(&farm);
		//ft_putendl(farm.file);
		send_ants(&farm);
	}
	return (0);
}
