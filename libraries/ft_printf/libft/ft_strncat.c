/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:18:56 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/10/24 12:59:05 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t len)
{
	size_t i;
	size_t j;

	j = -1;
	i = ft_strlen(dest);
	while (++j < len && src[j])
		dest[i++] = src[j];
	dest[i] = '\0';
	return (dest);
}
