/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 20:08:26 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/14 00:45:21 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_queue	*ft_queuenew(void *content, size_t content_size, char *id)
{
	t_queue *new;

	if (!(new = (t_queue *)malloc(sizeof(t_queue))))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = content;
		new->content_size = content_size;
		new->called_by = "default";
		new->id = id;
		new->ants = 0;
		new->next = NULL;
		new->parralel = NULL;
		new->previous = NULL;
		new->distance = 0;
		new->c_ant = 0;
	}
	new->next = NULL;
	return (new);
}
