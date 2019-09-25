/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 13:53:16 by sazalee           #+#    #+#             */
/*   Updated: 2019/09/25 17:16:31 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		tester(t_tetris *begin, char **finalb, int finalsize)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if ((begin->tetrimino[i][j] == '#') && (begin->x + j >= finalsize
						|| begin->y + i >= finalsize))
				return (0);
			if ((begin->tetrimino[i][j] == '#') && (finalb[begin->y + i][begin->x + j] >= 'A' &&
						finalb[begin->y + i][begin->x + j] <= 'Z'))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

char	**adder(t_tetris *begin, char **finalb)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (begin->tetrimino[i][j] == '#')
				finalb[begin->y + i][begin->x + j] = begin->alphabet;
			j++;
		}
		j = 0;
		i++;
	}
	return (finalb);
}

char	**cleaner(t_tetris *begin, char **finalb)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (finalb[x] != NULL)
	{
		while (finalb[x][y] != '\0')
		{
			if (finalb[x][y] == begin->alphabet)
				finalb[x][y] = '.';
			y++;
		}
		y = 0;
		x++;
	}
	return (finalb);
}

int		finder(t_tetris *begin, int finalsize, char **finalb)
{
	if (begin != NULL)
	{
		while (begin->x * begin->y < finalsize * finalsize)
		{
			if ((tester(begin, finalb, finalsize)) == 1)
			{
				finalb = adder(begin, finalb);
				if (finder(begin->next, finalsize, finalb) == 1)
					return (1);
				finalb = cleaner(begin, finalb);
			}
			if (begin->x < finalsize)
				begin->x++;
			else
			{
				begin->x = 0;
				begin->y++;
			}
		}
		begin->x = 0;
		begin->y = 0;
		return (0);
	}
	return (1);
}

char	**solve(t_tetris *begin, int finalsize, char **finalb)
{
	leftup(begin);
	result_of_project(begin->tetrimino, 4);
	while (finder(begin, finalsize, finalb) == 0)
	{
		finalsize++;
		begin->x = 0;
		begin->y = 0;
		ft_freetime(finalb, finalsize);
		finalb = finalbase(finalsize);
	}
	result_of_project(finalb, finalsize);
	return (finalb);
}
