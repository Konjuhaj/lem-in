/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 17:51:09 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/04/13 13:53:24 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		find_paths(t_room **room, t_room **sink, int limit, int current)
{
	int i;
	int ret;
	t_room *base;

	i = 0;
	if (limit == current)
		return (1);
	while (*room != *sink)
	{
		(*room)->distance = current;
		(*room)->visited++;
		while ((*room)->pipe[i])
		{
			base = (*room)->pipe[i];
			while (base->visited > 1 && (*room)->pipe[i + 1])
				base = (*room)->pipe[++i];
			if ((ret = find_paths(&base, sink, limit, current + 1)) == 1)
				break ;
			else if (ret == 3 && ++(*room)->length && ++(*room)->visited)
				return (3);
			i++;
		}
		return (2);
	}
	return (3);
}
