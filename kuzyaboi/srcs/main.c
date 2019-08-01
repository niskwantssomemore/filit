/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:30:01 by sazalee           #+#    #+#             */
/*   Updated: 2019/08/01 16:49:33 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"
#include <stdio.h>

void	ft_error(void)
{
	write(1, "error\n", 6);
}

void	ft_freetime(char **base, int counter)
{
	while (counter > 0)
	{
//		printf("counter = %d\n", counter);
		free(base[counter]);
		counter--;
	}
	free(base[0]);
}

int		main(int ac, char **av)
{
	t_tetris	*begin;
	char		**base;
	int index;
//	char **tetris;

	index = 0;
	begin = NULL;
	base = NULL;
	if (ac != 2)
	{
		ft_error();
		return (-1);
	}
	if ((base = ft_read(av[1])) == NULL)
	{
		ft_error();
		return (-1);
	}
	if (!(check(base)))
	{
		ft_error();
//		ft_freetime(base, g_tetrinumber);
		return (-1);
	}
	ft_freetime(base, g_tetrinumber);
	printf("g_n = %d\n", g_tetrinumber);
	while (index < g_tetrinumber)
	{
		printf("base[%d] = %s\n", index, base[index]);
		index++;
	}
//	begin = addtetri(base);
/*	while (begin)
	{
		tetris = begin->tetrimino;
		while (tetris[index])
		{
			printf("tetris[%d] = %s\n", index, tetris[index]);
			index++;
		}
		index = 0;
		printf("alphabet = %d\n", begin->alphabet);
		begin = begin->next;
	}*/
	return (0);
}
