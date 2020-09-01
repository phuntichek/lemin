/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 16:34:18 by phuntik           #+#    #+#             */
/*   Updated: 2020/07/22 18:25:44 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			init_lem(t_lemin *lem)
{
	lem->count_rooms = 0;
	lem->room = NULL;
	lem->link = NULL;
	lem->head = init_head();
	lem->end = init_end();
	lem->start = init_start();
	lem->aunt = init_aunt();
	lem->table = NULL;
	lem->statuses = NULL;
	lem->copy = NULL;
	lem->map = NULL;
}

t_start			*init_start(void)
{
	t_start		*start;

	if (!(start = (t_start *)ft_memalloc(sizeof(t_start))))
		exit(EXIT_FAILURE);
	start->name = NULL;
	start->x = 0;
	start->y = 0;
	return (start);
}

t_end			*init_end(void)
{
	t_end		*end;

	if (!(end = (t_end *)ft_memalloc(sizeof(t_end))))
		exit(EXIT_FAILURE);
	end->name = NULL;
	end->x = 0;
	end->y = 0;
	return (end);
}

t_head			*init_head(void)
{
	t_head		*head;

	if (!(head = (t_head *)ft_memalloc(sizeof(t_head))))
		exit(EXIT_FAILURE);
	head->first_link = NULL;
	head->first_room = NULL;
	return (head);
}

t_aunt			*init_aunt(void)
{
	t_aunt		*aunt;

	if (!(aunt = (t_aunt *)ft_memalloc(sizeof(t_aunt))))
		exit(EXIT_FAILURE);
	aunt->c = 0;
	return (aunt);
}
