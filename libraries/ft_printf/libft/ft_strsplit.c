/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:01:10 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/09/03 11:28:34 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**ft_strsplit(char const *s, char c)
{
	char	**splt;
	int		w_len;
	int		len;
	int		i;
	int		w;

	i = -1;
	w = 0;
	len = ft_strlen(s);
	if (!s || (!(splt = (char **)malloc(sizeof(char *) *
	(ft_wcount(s, c) + 1)))))
		return (NULL);
	while (++i < len)
	{
		if ((i == 0 && s[i] != c) || ((s[i - 1] == c) && s[i] != c))
		{
			w_len = ft_wlen(s + i, c);
			splt[w] = ft_strnew(w_len + 1);
			ft_strncpy(splt[w], s + i, w_len);
			splt[w++][w_len] = '\0';
		}
	}
	splt[w] = NULL;
	return (splt);
}
