/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:51:13 by aminadzh          #+#    #+#             */
/*   Updated: 2018/01/03 16:41:32 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Creates an array that is a figure
** Used in validation of file
*/

char	**tet_new(char *s)
{
	char	**t_new;
	char	*p_s;

	p_s = ft_strnew(21);
	p_s = ft_strncpy(p_s, s, 20);
	t_new = ft_strsplit(p_s, '\n');
	if (!(valid_sym_count(t_new)))
		return (NULL);
	if (!(valid_tet(t_new)))
		return (NULL);
	return (t_new);
}

/*
** Checks if we have only '.' and '#' and their right position
*/

int		valid_sym_count(char **tet)
{
	int		x;
	int		y;
	int		count;

	y = 0;
	count = 0;
	while (tet[y])
	{
		x = 0;
		while (tet[y][x])
		{
			if (tet[y][x] == '#')
				count++;
			x++;
		}
		y++;
	}
	return (count == 4) ? (1) : (0);
}

/*
** Checks if a figure is actually tetrimino
*/

int		valid_tet(char **tet)
{
	int		x;
	int		y;
	int		p;

	y = 0;
	p = 0;
	while (tet[y])
	{
		x = 0;
		while (tet[y][x])
		{
			if (tet[y][x] == '#' && tet[y][x + 1] == '#')
				p++;
			if (tet[y + 1] && tet[y][x] == '#' && tet[y + 1][x] == '#')
				p++;
			x++;
		}
		y++;
	}
	return (p == 4 || p == 3) ? (1) : (0);
}

/*
** Check for maximum 26 tetrimino, length of lines and empty lines btw figures
*/

int		valid_sym(char *s)
{
	int		i;
	int		t;
	int		c;

	if (ft_strlen(s) < 19)
		return (0);
	i = 0;
	t = 0;
	while (s[i] != '\0')
	{
		c = 1;
		while (c < 21 && s[i] != '\0')
		{
			if ((c % 5 == 0) && s[i] != '\n')
				return (0);
			if ((c % 5 != 0) && s[i] != '.' && s[i] != '#')
				return (0);
			i++;
			c++;
		}
		if ((s[i++] != '\n' && s[i] != '\0') || (++t > 26))
			return (0);
	}
	return (last_n(s)) ? (0) : (1);
}

/*
** Checks the last empty line
*/

int		last_n(char *s)
{
	int		len;

	len = ft_strlen(s);
	if (s[len - 1] == '\n' && s[len - 2] == '\n')
		return (1);
	return (0);
}
