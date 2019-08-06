/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 13:53:16 by sazalee           #+#    #+#             */
/*   Updated: 2019/08/06 13:30:43 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		tester(t_tetris *begin, char **finalbase, int finalsize)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (begin->tetrimino[i][j] == '#' && (begin->x + i >= finalsize
						|| begin->y + j >= finalsize)
					&& (finalbase[begin->x + i][begin->y + j] >= 'A' &&
						finalbase[begin->x + i][begin->y + j] <= 'Z'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**adder(t_tetris *begin, char **finalbase)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (begin->tetrimino[i][j] == '#')
				finalbase[begin->x + i][begin->y + j] = begin->alphabet;
			j++;
		}
		i++;
	}
	return (finalbase);
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
	while (finder(begin, finalsize, finalb) == 0)
	{
		finalsize++;
		begin->x = 0;
		begin->y = 0;
		ft_freetime(finalb, finalsize);
		finalb = finalbase(finalsize);
	}
	return (finalb);
}
