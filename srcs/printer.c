/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 17:38:36 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/24 18:11:36 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	print_queue_id(t_queue *queue)
{
	t_queue *temp;

	temp = queue;
	while (temp)
	{
		ft_printf("(%s) => ", temp->id);
		temp = temp->next;
	}
	ft_putstr("\n");
}

void	print_set(t_combinations *set)
{
	t_queue *test;

	test = set->set;
	ft_printf("\nSET Lines required: %d\n", set->print + 1);
	while (test)
	{
		ft_printf("Ants: %d, Distance %d \n", test->ants, test->distance);
		print_queue_id(test);
		test = test->parralel;
	}
	ft_printf("\n");
}

void	print_info(t_farm *farm)
{
	if (farm->op->info)
		print_set(best_path(farm->paths->next));
	if (farm->op->paths)
		print_set(farm->paths);
}
