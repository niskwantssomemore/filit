/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:30:01 by sazalee           #+#    #+#             */
/*   Updated: 2019/08/05 16:29:59 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_error(void)
{
	write(1, "error\n", 6);
}

void	ft_freetime(char **base, int counter)
{
	while (counter >= 0)
	{
		ft_strdel(&base[counter]);
		counter--;
	}
	ft_strdel(base);
}

int		main(int ac, char **av)
{
	t_tetris	*begin;
	char		**base;
	char		**finalb;
	int			finalsize;
	int index;

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
		ft_freetime(base, g_tetrinumber);
		return (-1);
	}
	begin = addtetri(base);
	while (begin)
	{
		index = 0;
		while (index < g_tetri_number)
		{
			printf("%s\n", begin->tetrimino[index]);
			index++;
		}
		begin = begin->next;
	}
	ft_freetime(base, g_tetrinumber);
	finalsize = ressize();
	finalb = finalbase(finalsize);
	solve(begin, finalsize, finalb);
}
