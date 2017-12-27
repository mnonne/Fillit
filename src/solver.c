/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 16:25:40 by aminadzh          #+#    #+#             */
/*   Updated: 2017/12/21 18:04:41 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_p		*create_matrix(char **tet)
{
	t_p		*matrix;
	t_p		*point;
	int		x;
	int		y;
	int		i;

	matrix = (t_p *)malloc(sizeof(t_p) * 4);
	point = (t_p *)malloc(sizeof(int) * 2);
	i = 0;
	y = 0;
	while (tet[y++])
	{
		x = 0;
		while (tet[y - 1][x++])
		{
			if (tet[y - 1][x - 1] == '#')
			{
				point->x = x;
				point->y = y;
				matrix[i++] = *point;
			}
		}
	}
	trim_matrix(matrix);
	return (matrix);
}

void	trim_matrix(t_p *mat)
{
	int		i;
	int		minx;
	int		miny;

	i = 0;
	minx = 3;
	miny = 3;
	while (i < 4)
	{
		if (mat[i].x <= minx)
			minx = mat[i].x;
		if (mat[i].y <= miny)
			miny = mat[i].y;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		mat[i].x = mat[i].x - minx;
		mat[i].y = mat[i].y - miny;
		i++;
	}
}

t_list	*create_lst(char ***tet)
{
	t_list	*lst;
	t_list	*p_lst;
	int		i;
	char	let;

	let = 'A';
	lst = lst_nu(tet[0], sizeof(t_tet), let);
	p_lst = lst;
	i = 1;
	while (tet[i])
	{
		let++;
		p_lst->next = lst_nu(tet[i], sizeof(t_tet), let);
		i++;
		p_lst = p_lst->next;
	}
	return (lst);
}

t_list	*lst_nu(char **tet, size_t content_size, char let)
{
	t_list	*l_new;
	int		i;

	if (!(l_new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	i = 0;
	if (tet)
	{
		if (!(l_new->content = create_tetrimino(tet, let)))
			return (NULL);
		l_new->content_size = content_size;
	}
	else
	{
		l_new->content = NULL;
		l_new->content_size = 0;
	}
	l_new->next = NULL;
	return (l_new);
}
