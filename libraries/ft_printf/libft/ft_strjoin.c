/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 07:46:12 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/20 22:01:41 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		len;
	int		i;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	s3 = (char *)malloc(sizeof(char) * (len + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	s3 = ft_strcpy(s3, s1);
	while (s2[++i])
		s3[len++] = s2[i];
	s3[len] = '\0';
	return (s3);
}
