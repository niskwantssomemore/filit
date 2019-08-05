/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arranger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 12:53:03 by sazalee           #+#    #+#             */
/*   Updated: 2019/08/05 12:47:00 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char		**left(int xmin, char **field)
{

}

char		**up(int ymin, char **field)
{

}

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

	temp = begin;
	while (temp)
	{
		x = xmin(temp->tetrimino);
		left(x, temp->tetrimino);
		y = ymin(temp->tetrimino);
		up(y, temp->tetrimino);
		temp = temp->next;
	}
	return (begin);
}
