/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:17:53 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/10/30 17:44:06 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int remember;

	i = -1;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[++i] && needle[0] != '\0')
	{
		if (haystack[i] == needle[j])
		{
			remember = i;
			while (haystack[i] == needle[j++])
			{
				if (needle[j] == '\0')
					return ((char *)haystack + remember);
				i++;
			}
			j = 0;
			i = remember;
		}
	}
	return (NULL);
}
