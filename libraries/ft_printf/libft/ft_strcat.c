/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:18:56 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/10/27 12:30:46 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;

	j = -1;
	i = ft_strlen(dest) - 1;
	while (src[++j])
		dest[++i] = src[j];
	dest[++i] = '\0';
	return (dest);
}
