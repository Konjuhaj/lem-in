/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 18:32:18 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/03/08 15:27:59 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	stack_to_heap(char **stack, char **line)
{
	char	*temp;
	int		i;

	i = 0;
	free(*line);
	while ((*stack)[i] != '\0' && (*stack)[i] != '\n')
		i++;
	if ((*stack)[i] == '\0')
	{
		*line = ft_strdup(*stack);
		ft_strdel(stack);
	}
	else
	{
		*line = ft_strsub(*stack, 0, i);
		temp = ft_strdup(&(*stack)[i + 1]);
		free(*stack);
		*stack = temp;
		if ((*stack)[0] == '\0')
			ft_strdel(stack);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*stack[MAX_FD];
	char		buff[BUFF_SIZE + 1];
	int			ret;
	char		*temp;

	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret < 0 || fd < 0 || !line || fd >= MAX_FD || BUFF_SIZE < 1)
			return (-1);
		buff[ret] = '\0';
		if (!stack[fd])
			stack[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(stack[fd], buff);
			free(stack[fd]);
			stack[fd] = temp;
		}
		if (ft_strchr(stack[fd], '\n') != NULL)
			break ;
	}
	*line = ft_strnew(1);
	if (ret == 0 && stack[fd] == NULL)
		return (0);
	return (stack_to_heap(&stack[fd], line));
}
