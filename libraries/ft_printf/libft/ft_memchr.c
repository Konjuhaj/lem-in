/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:21:44 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/10/27 16:19:24 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const char *ptr;

	ptr = str;
	while (n-- > 0)
	{
		if (*ptr == c)
			return ((void*)ptr);
		ptr++;
	}
	return (NULL);
}
