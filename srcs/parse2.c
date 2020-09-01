/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 20:28:10 by phuntik           #+#    #+#             */
/*   Updated: 2020/08/10 16:48:53 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			parse1(t_lemin **lem, char *line)
{
	if (ft_strequ(line, "##start") == 1)
	{
		write_start_room(lem);
		(*lem)->count_rooms++;
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		write_end_room(lem);
		(*lem)->count_rooms++;
	}
}

void			parse_one_room(t_lemin **lem, char **line, char ***split)
{
	if (check_coord((*split)[1]) && check_coord((*split)[2]))
	{
		(*lem)->room = (*lem)->head->first_room;
		if ((*lem)->room == NULL)
		{
			(*lem)->room = (t_room *)malloc(sizeof(t_room));
			(*lem)->room->name = NULL;
			(*lem)->room->next = NULL;
			write_room(lem, line);
		}
		else
		{
			while ((*lem)->room->next)
				(*lem)->room = (*lem)->room->next;
			(*lem)->room->next = (t_room *)malloc(sizeof(t_room));
			(*lem)->room->next->name = NULL;
			(*lem)->room->next->next = NULL;
			(*lem)->room = (*lem)->room->next;
			write_room(lem, line);
		}
		(*lem)->count_rooms++;
	}
	else
		handle_err("invalid room", lem, split, line);
}

void			parse_first_link(t_lemin **lem, char **line)
{
	if ((*lem)->count_rooms == 0)
		handle_err("no rooms", lem, 0, line);
	add_start_end(lem);
	if (!((*lem)->link = (t_link *)malloc(sizeof(t_link))))
		handle_err("cant create new lst for link", lem, 0, line);
	(*lem)->link->next = NULL;
	(*lem)->link->room1 = NULL;
	(*lem)->link->room2 = NULL;
}

bool			parse_rooms(t_lemin **lem)
{
	char		*line;
	char		**split;

	while (get_next_line((*lem)->fd, &line))
	{
		add_str_to_map(lem, line);
		if (line[0] == '#')
		{
			parse1(lem, line);
			free(line);
			continue ;
		}
		else if (ft_strchr(line, ' ') == NULL)
		{
			parse_first_link(lem, &line);
			write_link(lem, &line);
			free(line);
			return (true);
		}
		split = ft_strsplit(line, ' ');
		parse_one_room(lem, &line, &split);
		ft_free_arr(&split);
		free(line);
	}
	return (true);
}

bool			parse_links(t_lemin **lem)
{
	char		*line;

	while (get_next_line((*lem)->fd, &line) == 1)
	{
		add_str_to_map(lem, line);
		if (line[0] == '#' && line[1] != '#')
		{
			free(line);
			continue ;
		}
		if (num_chr(line, '-') == 0 || num_chr(line, ' ') > 0)
			handle_err("it is not a link", lem, 0, &line);
		(*lem)->link->next = (t_link *)malloc(sizeof(t_link));
		(*lem)->link->next->next = NULL;
		(*lem)->link->next->room1 = NULL;
		(*lem)->link->next->room2 = NULL;
		(*lem)->link = (*lem)->link->next;
		write_link(lem, &line);
		free(line);
	}
	return (true);
}
