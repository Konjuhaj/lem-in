/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 19:14:59 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/09 11:24:18 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
# define LEM_IN
# define MAX_INT  2147483647
# include "../libraries/ft_printf/includes/ft_printf.h"

typedef struct		s_room
{
	void			**pipe;
	int				visited;
	int				length;
	int				distance;
	char			*name;
}					t_room;

typedef struct		s_queue
{
	void			*content;
	size_t			content_size;
	void			*next;
	void			*parralel;
	char			*called_by;
	char			*id;
}					t_queue;

typedef struct		s_combinations
{
	t_queue			*set;
	int				max_flow;
	int				min_cut;
	void			*next;
}					t_combinations;

typedef struct	s_farm
{
	t_combinations	*paths;
	t_room			**rooms;
	t_room			*source;
	t_room			*sink;
	int				ants;
	int				bottleneck;
}					t_farm;

void				ft_errno(void);

void				find_paths(t_room *room, char *end, char *id, t_farm *farm);

void				connect_rooms(char **s, t_farm *farm, int i);

int					read_rooms(char **s, t_farm *farm);

/*
**					TESTING FUNCTUION
*/

void				print_queue_id(t_queue *queue);

void				print_sets(t_combinations *set);

void				print_set(t_combinations *set);

/*
**					QUEUE Functions
*/

void				ft_queueadd(t_queue **alst, t_queue *new, char *caller);

t_queue				*ft_queuenew(void *content, size_t content_size, char *id);

t_queue				*ft_dequeue(t_queue **queue);

void				ft_queueaddfront(t_queue **queue, t_queue *new);

void				*ft_queuefind(t_queue **queue, char *id);

/*
**					HELPER FUNCTIONS
*/

void				save_path(t_queue *path, t_farm *farm);

/*
**					COMBINATIONS
*/

void				combinations(t_farm *farm);



#endif
