/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 21:58:11 by phuntik           #+#    #+#             */
/*   Updated: 2020/08/09 12:30:12 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

bool			write_link(t_lemin **lem, char **line)
{
	if ((*lem)->head->first_link == NULL)
		(*lem)->head->first_link = (*lem)->link;
	if (num_chr(*line, '-') < 1)
		handle_err("write link: no -", lem, 0, line);
	if (num_chr(*line, '-') == 1)
		link_first_type(lem, line);
	if (num_chr(*line, '-') > 1)
		link_second_type(lem, line);
	if (!validation(lem))
		handle_err("write link: validation error", lem, 0, line);
	return (true);
}

int				while_link_first_type(t_lemin **lem, char **line, char **split)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while ((*lem)->room->next != NULL)
	{
		if (ft_strequ(split[0], (*lem)->room->name))
			i++;
		if (ft_strequ(split[1], (*lem)->room->name))
			j++;
		if (i == 1 && j == 1)
			break ;
		(*lem)->room = (*lem)->room->next;
	}
	if (i == 0 && (ft_strequ(split[0], (*lem)->start->name)
	|| ft_strequ(split[0], (*lem)->end->name)))
		i++;
	if (j == 0 && (ft_strequ(split[1], (*lem)->start->name)
	|| ft_strequ(split[1], (*lem)->end->name)))
		j++;
	if (i == 1 && j == 1)
		return (-1);
	return (!(i > 1 || j > 1));
}

bool			link_first_type(t_lemin **lem, char **line)
{
	char		**split;
	int			i;

	if (!(*line))
		handle_err("links first type: no line", lem, 0, line);
	split = ft_strsplit(*line, '-');
	(*lem)->room = (*lem)->head->first_room;
	i = while_link_first_type(lem, line, split);
	if (i == -1)
	{
		(*lem)->link->room1 = ft_strdup(split[0]);
		(*lem)->link->room2 = ft_strdup(split[1]);
	}
	else if (i == 0)
		handle_err("links first type: doubles!", lem, &split, line);
	else
		handle_err("links first type: no rooms", lem, &split, line);
	ft_free_arr(&split);
	return (true);
}

bool			link_second_type(t_lemin **lem, char **line)
{
	int			i;

	i = 0;
	(*lem)->room = (*lem)->head->first_room;
	while ((*lem)->room)
	{
		if (ft_strstr(*line, (*lem)->room->name) == *line)
		{
			(*lem)->link->room1 = ft_strdup((*lem)->room->name);
			(*lem)->room = (*lem)->head->first_room;
			while ((*lem)->room)
			{
				if (ft_strstr(*line, (*lem)->room->name)
				== *line + ft_strlen((*lem)->link->room1) + 1)
				{
					(*lem)->link->room2 = ft_strdup((*lem)->room->name);
					return (true);
				}
				(*lem)->room = (*lem)->room->next;
			}
			break ;
		}
		(*lem)->room = (*lem)->room->next;
	}
	return (false);
}
