/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 13:53:16 by sazalee           #+#    #+#             */
/*   Updated: 2019/08/05 13:28:15 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

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

}

char	**solve(t_tetris *begin, int finalsize, char **finalb)
{
	leftup(begin);
	while (finder(begin, finalsize, finalb) == 0)
	{
		freetime(finalb, finalsize);
		finalb = finalbase(finalsize);
	}
	return (finalb);
}
