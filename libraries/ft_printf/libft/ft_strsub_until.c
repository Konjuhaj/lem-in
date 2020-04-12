/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 12:08:34 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/04/12 18:42:19 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub_until(char *s, char c)
{
	int		len;
	char	*str;

	len = 0;
	str = NULL;
	while (s[len] != c)
		len++;
	if(!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strncpy(str, s, len);
	str[len] = '\0';
	return (str);
}
