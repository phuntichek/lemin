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

void			parser(t_lemin **lem)
{
	t_room	*room;

	if (!parse_aunt(lem))
		handle_err("end of parse aunt", lem, 0, 0);
	if (!parse_rooms(lem))
		handle_err("end of parse rooms", lem, 0, 0);
	if (!(parse_links(lem)))
		handle_err("end of parse links", lem, 0, 0);
	(*lem)->room = (*lem)->head->first_room;
	(*lem)->link = (*lem)->head->first_link;
}

int				check_str(char *str)
{
	int		flag;

	if (ft_strlen(str) - (*str == '-' || *str == '+') < 10)
		return (0);
	if (ft_strlen(str) - (*str == '-' || *str == '+') > 10)
		return (1);
	flag = *str == '-';
	str += flag || *str == '+';
	if (str[0] >= '2')
		if (str[1] >= '1')
			if (str[2] >= '4')
				if (str[3] >= '7')
					if (str[4] >= '4')
						if (str[5] >= '8')
							if (str[6] >= '3')
								if (str[7] >= '6')
									if (str[8] >= '4')
										if ((!flag && str[9] > '7')
										|| (flag && str[9] > '8'))
											return (1);
	return (0);
}

bool			check_coord(char *num)
{
	int i;

	if ((num[0] == '-' || num[0] == '+') && num[1] == '\0')
		return (0);
	i = (num[0] == '-' || num[0] == '+');
	while (num[i] != '\0')
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (!check_str(num));
}

bool			parse_aunt(t_lemin **lem)
{
	char	*line;
	int		i;

	i = 0;
	if (get_next_line((*lem)->fd, &line) == 1)
	{
		add_str_to_map(lem, line);
		while (line[i])
		{
			if (line[i] < '0' || line[i] > '9')
				handle_err("invalid aunt", lem, 0, &line);
			i++;
		}
		if (!check_coord(line))
			handle_err("too big AUNT", lem, 0, &line);
		(*lem)->aunt->c = ft_atoi(line);
	}
	if ((*lem)->aunt->c <= 0 || (*lem)->aunt->c > 2147483647)
		handle_err("invalid aunt", lem, 0, &line);
	free(line);
	return (true);
}

void			add_start_end(t_lemin **lem)
{
	(*lem)->room = (*lem)->head->first_room;
	(*lem)->link = (*lem)->head->first_link;
	while ((*lem)->room->next != NULL)
		(*lem)->room = (*lem)->room->next;
	if (!((*lem)->start->name))
		handle_err("no start room", lem, 0, 0);
	(*lem)->room->next = (t_room *)malloc(sizeof(t_room));
	(*lem)->room->next->name = ft_strdup((*lem)->start->name);
	(*lem)->room->next->x = (*lem)->start->x;
	(*lem)->room->next->y = (*lem)->start->y;
	(*lem)->room->next->next = NULL;
	if (!((*lem)->end->name))
		handle_err("no end room", lem, 0, 0);
	(*lem)->room->next->next = (t_room *)malloc(sizeof(t_room));
	(*lem)->room->next->next->name = ft_strdup((*lem)->end->name);
	(*lem)->room->next->next->x = (*lem)->end->x;
	(*lem)->room->next->next->y = (*lem)->end->y;
	(*lem)->room->next->next->next = NULL;
}
