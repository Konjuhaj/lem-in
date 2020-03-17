/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:20:34 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/10/21 14:19:29 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*destptr;
	unsigned char	*srcptr;
	size_t			i;

	i = -1;
	destptr = (unsigned char *)dst;
	srcptr = (unsigned char *)src;
	while (++i < n)
	{
		destptr[i] = srcptr[i];
		if (srcptr[i] == (unsigned char)c)
			return (dst + i + 1);
	}
	return (NULL);
}
