/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:27:20 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/10/31 08:55:38 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsplit(char *s, char c)
{
	size_t	i;
	int		word;
	t_list	*list;

	i = 0;
	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	while (i < ft_strlen(s))
	{
		if ((i == 0 && s[i] != c) || ((s[i - 1] == c) && s[i] != c))
		{
			word = ft_wlen(s + i, c);
			if (!(list->content = (char *)malloc(word * sizeof(char))))
				return (NULL);
			list->content = ft_strncpy(list->content, s + i, word);
			list->content_size = word;
			list->next = ft_lstsplit(s + i + word + 1, c);
			return (list);
		}
		i++;
	}
	return (NULL);
}
