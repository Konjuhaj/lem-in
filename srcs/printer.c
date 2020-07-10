/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 17:38:36 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/10 10:01:16 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		print_queue_id(t_queue *queue)
{
	t_queue *temp;

	temp = queue;
	while (temp)
	{
		ft_printf("%s(%d) -> ", temp->id, temp->distance);
		temp = temp->next;
	}
	ft_putstr("\n");
}

void		print_set(t_combinations *set)
{
	//testing
	t_queue *test;
	test = set->set;
	while (test)
	{
		print_queue_id(test);
		test = test->parralel;
	}
	ft_printf("\n");
}

void		print_sets(t_combinations *set)
{
	t_combinations	*temp;
	int				i;

	temp = set;
	i = 0;
	while (temp)
	{
		ft_printf("\nSET-%d M_F-%d, A-S%f\n", i++, temp->max_flow, temp->avg_speed);
		print_set(temp);
		temp = temp->next;
	}
}

