/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 19:14:59 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/29 17:53:42 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
# define LEM_IN
# define MAX_INT  2147483647
# include "../libraries/ft_printf/includes/ft_printf.h"

typedef struct		s_edge
{
	void			*next;
	int				current;
	void			*pair;
}					t_edge;

typedef struct		s_room
{
	t_edge			*edge;
	int				visited;
	int				path;
	char			*name;
}					t_room;

typedef struct		s_queue
{
	void			*content;
	size_t			content_size;
	void			*next;
	void			*previous;
	void			*parralel;
	char			*called_by;
	int				distance;
	int				ants;
	int				c_ant;
	char			*id;
}					t_queue;

typedef struct		s_combinations
{
	t_queue			*set;
	int				max_flow;
	double			avg_speed;
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

void				find_paths(t_room *room, char *end, t_farm *farm);

void				find_paths2(t_room *room, char *end, t_farm *farm);

void				find_shortest(t_room *room, char *end, t_farm *farm);

void				connect_rooms(char **s, t_farm *farm, int i);

int					read_rooms(char **s, t_farm *farm);

/*
**					TESTING FUNCTUION
*/

void				print_queue_id(t_queue *queue);

void				print_queue_id_rev(t_queue *queue);

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

void				ft_free_queue(t_queue *queue);

/*
**					HELPER FUNCTIONS
*/

void				save_path(t_queue *path, t_farm *farm);

void				store_path(t_queue *queue, char *first, t_farm *farm);


/*
**					COMBINATIONS
*/

void				combinations(t_farm *farm);

/*
**					CHECKER
*/

int					are_duplicates(t_queue *new, t_queue *base, t_room *sink);

/*
**					SEND ANTS
*/

void				send_ants(t_farm *farm);

#endif
