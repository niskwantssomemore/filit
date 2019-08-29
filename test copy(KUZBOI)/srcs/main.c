/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:30:01 by sazalee           #+#    #+#             */
/*   Updated: 2019/08/29 15:12:46 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_error(void)
{
	write(1, "error\n", 6);
}

void	ft_freetime(char **base, int counter)
{
	int flag;

	flag = 0;
	while (flag < counter)
	{
		ft_strdel(&base[flag]);
		flag++;
	}
	ft_strdel(base);
}

void	result_of_project(char **finalb, int finalsize)
{
	int index;
	int jndex;

	index = 0;
	while (index < finalsize)
	{
		jndex = 0;
		while (jndex < finalsize)
		{
			ft_putchar(finalb[index][jndex]);
			jndex++;
		}
		ft_putchar('\n');
		index++;
	}
}

int		main(int ac, char **av)
{
	t_tetris	*begin;
	char		**base;
	char		**finalb;
	int			finalsize;

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
	ft_freetime(base, g_tetrinumber + 1);
	finalsize = ressize();
	finalb = finalbase(finalsize);
	solve(begin, finalsize, finalb);
	/*result_of_project(finalb, finalsize);*/
}
