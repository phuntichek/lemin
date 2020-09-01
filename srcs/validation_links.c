/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_links.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 19:45:34 by phuntik           #+#    #+#             */
/*   Updated: 2020/08/09 14:15:00 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

bool			validation(t_lemin **lem)
{
	if (!(check_doubles(lem)))
		handle_err("validation: cant check doubles", lem, 0, 0);
	return (true);
}

void			while_check_doubles(t_lemin **lem, char **r1, char **r2)
{
	t_link		*help;
	int			i;

	i = 0;
	help = (*lem)->head->first_link;
	while (help->next)
	{
		if (ft_strequ(help->room1, *r1) && ft_strequ(help->room2, *r2))
			i++;
		help = help->next;
	}
	if (i > 0)
	{
		free(*r1);
		free(*r2);
		handle_err("check doubles: invalid room 1", lem, 0, 0);
	}
}

bool			check_doubles(t_lemin **lem)
{
	int			i;
	char		*r1;
	char		*r2;
	t_link		*help;

	i = 0;
	r1 = ft_strdup((*lem)->link->room1);
	r2 = ft_strdup((*lem)->link->room2);
	while_check_doubles(lem, &r1, &r2);
	help = (*lem)->head->first_link;
	while (help)
	{
		if (ft_strequ(help->room1, r2) && ft_strequ(help->room2, r1))
			i++;
		help = help->next;
	}
	if (i > 0)
	{
		free(r1);
		free(r2);
		handle_err("check doubles: invalid room 2", lem, 0, 0);
	}
	free(r1);
	free(r2);
	return (true);
}
