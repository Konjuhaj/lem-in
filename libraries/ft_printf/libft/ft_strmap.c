/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 06:45:43 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/10/26 14:39:42 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s2;
	int		i;

	i = -1;
	if (!s || !(s2 = ft_strdup((char*)s)))
		return (NULL);
	while (s[++i])
		s2[i] = f(s[i]);
	return (s2);
}
