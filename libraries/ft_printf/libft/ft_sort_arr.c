/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:27:15 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/20 21:40:54 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*sort_arr(int *arr, int size)
{
	int swap;
	int i;

	while (size)
	{
		i = -1;
		while (++i < size)
		{
			if (arr[i] > arr[i + 1])
			{
				swap = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = swap;
				i = -1;
			}
		}
		size--;
	}
	return (arr);
}
