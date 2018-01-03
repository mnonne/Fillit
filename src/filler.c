/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:54:09 by aminadzh          #+#    #+#             */
/*   Updated: 2018/01/03 20:01:24 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Counts the needed size of a map
*/

int		count_map_size(t_list *lst)
{
	int		n;
	int		size;

	n = 0;
	while (lst)
	{
		n++;
		lst = lst->next;
	}
	size = sqroot(n);
	return (size);
}

/*
** Finds the closest square root to calc the min map size
*/

int		sqroot(int n)
{
	int		sqrt;
	int		i;
	int		nb;

	sqrt = 0;
	i = 1;
	nb = n;
	while (nb > 0)
	{
		nb = nb - i;
		i += 2;
		if (nb >= 0)
			sqrt += 1;
	}
	if (nb >= 0)
		return (sqrt);
	else
		return (sqroot(n + 1));
}

/*
** Backtracking recursive algorythm to fill the map
*/

int		fill_map(t_map *map, t_list *lst)
{
	t_p		pos;
	int		to_del;

	if (!lst)
		return (1);
	pos.y = 0;
	while (pos.y < map->m_size)
	{
		pos.x = 0;
		while (pos.x < map->m_size)
		{
			if ((to_del = place_tet(map, pos, lst)) == 0)
			{
				if (fill_map(map, lst->next))
					return (1);
				del_tet(map, pos, lst, 5);
			}
			else
				del_tet(map, pos, lst, to_del);
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}

/*
** A function to solve the problem
** Calls the main algorythm and increases the map size if needed
*/

t_map	*solve(t_list *lst)
{
	t_map	*map;
	int		size;

	size = count_map_size(lst);
	map = new_map(size);
	while (!(fill_map(map, lst)))
	{
		size++;
		free_map(map);
		map = new_map(size);
	}
	return (map);
}
