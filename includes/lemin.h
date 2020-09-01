/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 15:04:06 by phuntik           #+#    #+#             */
/*   Updated: 2020/08/10 16:42:31 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define MAX_INT 2147483647

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				c;
	struct s_room	*next;
}					t_room;

typedef struct		s_link
{
	char			*room1;
	char			*room2;
	struct s_link	*next;
}					t_link;

typedef struct		s_start
{
	char			*name;
	int				x;
	int				y;
}					t_start;

typedef struct		s_end
{
	char			*name;
	int				x;
	int				y;
}					t_end;

typedef struct		s_head
{
	t_room			*first_room;
	t_link			*first_link;
}					t_head;

typedef struct		s_aunt
{
	int				c;
}					t_aunt;

typedef struct		s_map
{
	char			*line;
	struct s_map	*next;
}					t_map;

typedef struct		s_lemin
{
	t_room			*room;
	int				count_rooms;
	t_link			*link;
	t_start			*start;
	t_end			*end;
	t_head			*head;
	t_aunt			*aunt;
	bool			**table;
	bool			*statuses;
	bool			*copy;
	int				count_paths;
	int				fd;
	t_map			*map;
}					t_lemin;

typedef struct		s_paths
{
	int				*path;
	int				len;
	int				ants;
	struct s_paths	*next;
}					t_paths;

void				free_lemin(t_lemin **info, t_paths **paths);
void				init_lem(t_lemin *info);
t_room				*init_room();
t_link				*init_link();
t_start				*init_start();
t_end				*init_end();
t_head				*init_head();
t_aunt				*init_aunt();
void				parser(t_lemin **lem);
bool				parse_aunt(t_lemin **lem);
bool				parse_rooms(t_lemin **lem);
bool				parse_links(t_lemin **lem);
bool				handle_err(char *str, t_lemin **lem,
char ***split, char **line);
int					num_chr(char *line, char c);
bool				validation(t_lemin **lem);
bool				check_rooms(t_lemin **lem);
bool				check_doubles(t_lemin **lem);
bool				write_link(t_lemin **lem, char **line);
bool				link_first_type(t_lemin **lem, char **line);
bool				link_second_type(t_lemin **lem, char **line);
bool				write_start_room(t_lemin **lem);
bool				write_end_room(t_lemin **lem);
bool				write_room(t_lemin **lem, char **line);
bool				check_dublicate(t_lemin **lem, char **line);
void				add_start_end(t_lemin **lem);
char				*name_room(t_lemin *info, int index);
int					num_room(t_lemin *info, char *name);
void				print_result(t_lemin *info, t_paths *paths, int start);
t_paths				*get_all_paths(t_lemin *info);
int					*get_array_prev_rooms(t_lemin *info);
void				zeroing_bool(bool **stats, int count_rooms);
bool				check_this(bool *this_lvl, int count_rooms);
void				swap_and_zeroing(bool **this_lvl, bool **next_lvl,
int					count_rooms);
void				parse_room2(t_lemin **lem, char **line);
void				parse_link2(t_lemin **lem, char **line);
bool				check_coord(char *num);
int					check_str(char *str);
void				add_str_to_map(t_lemin **lem, char *line);
void				free_map(t_map **map);
void				print_map(t_map *map);

#endif
