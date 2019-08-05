/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 13:53:16 by sazalee           #+#    #+#             */
/*   Updated: 2019/08/05 13:02:31 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

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
}
