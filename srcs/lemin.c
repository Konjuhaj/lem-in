/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 23:23:43 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/04/10 16:21:52 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

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
		connect_rooms(file, farm, readst_rooms(file, farm));
		while (find_paths(&farm->source,&farm->sink, limit, 0) != 3)
			limit++;
		print_values(farm);
	}
	// s(ystem("leaks a)->out");
	return (0);
}
