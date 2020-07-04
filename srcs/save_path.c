/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 16:29:39 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/04 17:24:06 by bkonjuha         ###   ########.fr       */
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
	ft_putstr("ENDING\n");
}

void	save_path(t_queue *path)
{
	static t_combinations	*total_paths;
	static t_queue			*temp;

	total_paths = (t_combinations *)malloc(sizeof(t_combinations));
	if (!total_paths->set)
	{
		total_paths->set = path;
		total_paths->set->parralel = NULL;
	}
	else
	{
		temp = total_paths->set;
		temp->parralel = path;
		temp = temp->parralel;
		temp->parralel = NULL;
	}
	//testing

	t_queue *test;
	test = total_paths->set;
	while (test)
	{
		print_queue_id(test);
		test = test->parralel;
	}
}
