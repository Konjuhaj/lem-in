/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 20:08:26 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/06/04 10:48:09 by bkonjuha         ###   ########.fr       */
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
	}
	new->next = NULL;
	return (new);
}
