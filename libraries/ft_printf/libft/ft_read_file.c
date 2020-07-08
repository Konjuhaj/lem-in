/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 11:47:38 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/08 14:11:37 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_file(int fd)
{
	char buff[BUFF_SIZE + 1];
	char *temp;
	char *str;
	int ret;

	str = NULL;
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (!str)
			str = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(str, buff);
			free(str);
			str = temp;
		}
	}
	return (str);
}
