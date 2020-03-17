/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:23:59 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/10/25 11:54:29 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*destptr;
	const char	*srcptr;
	size_t		i;

	i = -1;
	destptr = dst;
	srcptr = src;
	if (!dst && !src)
		return (NULL);
	while (++i < n)
		destptr[i] = srcptr[i];
	return (dst);
}
