/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:19:29 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/10/26 13:58:34 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = -1;
	if (!(ptr = (unsigned char *)malloc((sizeof(unsigned char *) * len + 1))))
		return (NULL);
	while (++i < len + 1)
		ptr[i] = '\0';
	return ((void *)ptr);
}
