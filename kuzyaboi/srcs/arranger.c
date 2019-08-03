/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arranger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 12:53:03 by sazalee           #+#    #+#             */
/*   Updated: 2019/08/03 14:49:08 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ymin(char **field)
{
	int x;
	int y;
	int targety;

	x = 0;
	y = 0;
	targety = 0;
	while (x < 4)
	{
		while (field[x][y] != '#' && field[x][y] != '\0')
			y++;
		if (y == 4)
			targety++;
		else
			return (targety);
		y = 0;
		x++;
	}
	return (targety);
}

int			xmin(char **field)
{
	int	x;
	int	y;
	int	targetx;

	x = 0;
	y = 0;
	targetx = 4;
	while (x < 4)
	{
		while (field[x][y] != '#' && field[x][y] != '\0')
			y++;
		if (y < targetx)
			targetx = y;
		else
			targetx = targetx;
		y = 0;
		x++;
	}
	return (targetx);
}

t_tetris	*leftup(t_tetris *begin)
{
	t_tetris	*temp;
	int			x;
	int			y;

	x = xmin();
	y = ymin();
}
