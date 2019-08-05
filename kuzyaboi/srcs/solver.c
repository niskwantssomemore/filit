/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:48:15 by tstripeb          #+#    #+#             */
/*   Updated: 2019/08/05 15:06:25 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int tester(t_tetris *begin, char **finalbase, int finalsize)
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

char **adder(t_tetris *begin, char **finalbase)
{
	int i;
	int j;

	i
	   	= 0;
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
