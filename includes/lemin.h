/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 19:14:59 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/06/09 12:38:36 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
# define LEM_IN
# include "../libraries/ft_printf/includes/ft_printf.h"

typedef struct	s_room
{
	void			**pipe;
	int				visited;
	int				length;
	int				distance;
	char			*name;
}				t_room;


typedef struct	s_farm
{
	t_room			**rooms;
	t_room			*source;
	t_room			*sink;
	int				ants;
}					t_farm;

typedef struct		s_queue
{
	void			*content;
	size_t			content_size;
	struct s_queue	*next;
	char			*called_by;
	char			*id;
}					t_queue;

void				ft_errno(void);

void				find_paths(t_room *room, char *end, char *id);

void				connect_rooms(char **s, t_farm *farm, int i);

int					read_rooms(char **s, t_farm *farm);

/*
**					TESTING FUNCTUION
*/

void				print_values(t_farm *farm);


/*
**					QUEUE Functions
*/

void				ft_queueadd(t_queue **alst, t_queue *new, char *caller);

t_queue				*ft_queuenew(void *content, size_t content_size, char *id);

t_queue				*ft_dequeue(t_queue **queue);

void				ft_queueaddfront(t_queue **queue, t_queue *new);

t_queue				*ft_queuefind(t_queue **queue, char *id);

#endif
