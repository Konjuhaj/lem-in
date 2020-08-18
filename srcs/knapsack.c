/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knapsack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 17:35:57 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/18 19:37:13 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_queue *get_last_node(t_queue *queue)
{
	while (queue && queue->parralel)
		queue = queue->parralel;
	return (queue);
}

t_queue	*better_path(t_queue *queue, t_queue *queue2)
{
	int MF[2];
	float AS[2];
	t_queue *temp;
	t_queue *temp2;

	MF[0] = 0;
	AS[0] = 0;
	MF[1] = 0;
	AS[1] = 0;
	temp = queue;
	temp2 = queue2;
	while (queue)
	{
		MF[0]++;
		AS[0] += queue->distance;
		queue = queue->parralel;
	}
	AS[0] /= MF[0];
	while (queue2)
	{
		MF[1]++;
		AS[1] += queue2->distance;
		queue2 = queue2->parralel;
	}
	AS[1] /= MF[1];
	if (MF[0] > MF[1] || (MF[0] == MF[1] && AS[0] < AS[1]))
	{
		ft_free_queue(queue2);
		// ft_printf("returning: ");
		// print_queue_id(temp);
		// ft_printf("MF %d AS%f", MF[0], AS[0]);
		return (temp);
	}
	// ft_printf("NOT returning: ");
	// print_queue_id(temp2);
	ft_free_queue(queue);
	// ft_printf("MF %d AS%f", MF[1], AS[1]);
	return (temp2);
}

t_queue *add_to_queue(t_queue *full_q, t_queue *add, t_room *sink)
{
	t_queue *temp;

	temp = full_q;
	while (temp->parralel)
			temp = temp->parralel;
	if (!are_duplicates(add, full_q, sink))
	{
		temp->parralel = copy_path(add);
		return (full_q);
	}
	return (NULL);

}

t_queue	 *knapsack2(t_queue *original_q, t_queue *full_q, t_room *sink)
{
	t_queue *temp;
	t_queue *temp2;
	t_queue *full_q_plus;

	temp = full_q;
	temp2 = temp;
	while (original_q)
	{
		if (!full_q)
			temp = knapsack2(original_q->parralel, copy_path(original_q), sink);
		else if ((full_q_plus = add_to_queue(full_q, original_q, sink)))
			temp = knapsack2(original_q->parralel, full_q_plus, sink);
		temp2 = knapsack2(original_q->parralel, full_q, sink);
		return (better_path(temp, temp2));
	}
	return (full_q);
}

t_combinations	*knapsack(t_queue *queue, t_room *sink)
{
	t_combinations *comb;

	if (!(comb = (t_combinations *)malloc(sizeof(t_combinations) + 1)))
		ft_errno();
	comb->set = knapsack2(queue, NULL, sink);
	update_combination(comb);
	// ft_printf("catdog\n");
	// print_set(comb);
	return (comb);
}
