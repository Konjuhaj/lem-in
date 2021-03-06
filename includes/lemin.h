/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 19:14:59 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/09/03 11:47:20 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# define MAX_INT  2147483647
# define VISITED 2
# define STD_IN 0
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
	int				value;
	int				ants;
	int				c_ant;
	char			*id;
}					t_queue;

typedef struct		s_combinations
{
	t_queue			*set;
	int				*using;
	int				print;
	void			*next;
}					t_combinations;

typedef	struct		s_option
{
	int				paths;
	int				info;
	int				error;
	int				help;
}					t_option;

typedef struct		s_farm
{
	t_combinations	*paths;
	t_option		*op;
	t_room			**rooms;
	t_room			*source;
	t_room			*sink;
	char			*file;
	int				ants;
	int				count;
}					t_farm;

void				ft_errno(char *s, t_option *o);

void				find_paths(t_room *room, char *end, t_farm *farm);

void				find_paths2(t_room *room, char *end, t_farm *farm);

void				find_shortest(t_room *room, char *end, t_farm *farm);

void				connect_rooms(char **s, t_farm *farm, int i);

int					read_rooms(char **s, t_farm *farm);

void				reconstruct_path(t_room *sink,
					t_room *source, t_farm *farm);

int					bfs(t_room *start, t_room *end);

/*
**					INIT FUNCTIONS
*/

t_room				**init_all_rooms(int count);

t_room				*init_room(int edges);

t_combinations		*init_comb(void);

t_option			*init_option(void);

/*
**					VALIDATION FUNCTIONS
*/

void				validate_rooms(char **s);

char				**validate_instructions(char **s);

void				validate_lines(char *s);

void				check_duplicates(char **s);

void				check_path_to_source(t_farm *farm);

int					is_command_or_comment(char *s);

void				duplicate_room(t_farm *farm);

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

void				ft_queueaddback(t_queue **aqueue, t_queue *old);

void				ft_connect_queue(t_queue *path, t_room *sink);

void				reverse_connect(t_combinations *comb, t_room *sink);

/*
**					HELPER FUNCTIONS
*/

void				save_path(t_queue *path, t_farm *farm);

t_queue				*store_path(t_queue *queue, char *first, t_farm *farm);

t_queue				*copy_path(t_queue *paths);

void				remove_unused(t_queue *queue);

void				reset_ants(t_queue *queue);

t_combinations		*get_paths_in_use(t_combinations *comb);

void				calculate_ants_per_path(t_combinations *comb, int ants);

t_combinations		*best_path(t_combinations *comb);

void				update_length(t_combinations *comb);

void				print_info(t_farm *farm);

void				add_queue(t_queue *all, t_queue *new);

/*
**					COMBINATIONS
*/

void				combinations(t_farm *farm);

void				update_combination(t_combinations *comb);

void				improve_set2(t_queue *new,
					t_combinations *farm, t_room *sink);

t_queue				*get_smallest(t_combinations *comb, int i);

t_combinations		*short_comb(t_farm *farm);

/*
**					CHECKER
*/

int					are_duplicates(t_queue *new, t_queue *base, t_room *sink);

int					are_identical(t_queue *new, t_queue *all);

/*
**					SEND ANTS
*/

void				send_ants(t_farm *farm);

#endif
