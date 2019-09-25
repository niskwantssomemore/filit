/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arranger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 12:53:03 by sazalee           #+#    #+#             */
/*   Updated: 2019/09/25 17:30:25 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			xmin(char **field)
{
	int x;
	int y;
	int targetx;

	x = 0;
	y = 0;
	targetx = 4;
	while (x < 4)
	{
		while (field[x][y] != '#' && field[x][y] != '\0')
			y++;
		if (y < targetx)
			targetx = y;
		y = 0;
		x++;
	}
	return (targetx);
}

char		**left(int xmin, char **field)
{
	int	temp;
	int	x;
	int	y;

	temp = 0;
	x = 0;
	y = 0;
	while (x < 4)
	{
		while (field[x][y + xmin] != '\0')
		{
			field[x][y] = field[x][y + xmin];
			y++;
		}
		temp = xmin;
		while (temp > 0)
		{
			field[x][4 - temp] = '.';
			temp--;
		}
		y = 0;
		x++;
	}
	return (field);
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

char		**up(int ymin, char **field)
{
	int count;

	count = 0;
	while (count + ymin < 4)
	{
		field[count] = field[count + ymin];
		count++;
	}
	while (count < 4 && ymin > 0)
	{
		field[count] = "....\0";
		count++;
	}
	return (field);
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
		printf("%d", x);
		left(x, temp->tetrimino);
		y = ymin(temp->tetrimino);
		up(y, temp->tetrimino);
		temp = temp->next;
	}
	return (begin);
}
