/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:30:01 by sazalee           #+#    #+#             */
/*   Updated: 2019/08/29 15:43:59 by tstripeb         ###   ########.fr       */
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

int read_check_write(char *av, char **base, t_tetris **begin)
{
	int index;

	if ((base = ft_read(av)) == NULL || !(check(base)))
	{
		ft_error();
		ft_freetime(base, g_tetrinumber + 1);
		return (0);
	}
	*begin  = addtetri(base);
	ft_freetime(base, g_tetrinumber);
	return (1);
}

int		main(int ac, char **av)
{
	t_tetris	*begin;
	char		**base;
	int			finalsize;
	char		**finalb;

	begin = NULL;
	base = NULL;
	if (ac != 2)
	{
		ft_error();
		return (-1);
	}
	if (!(read_check_write(av[1], base, &begin)))
		return (-1);
	finalsize = ressize();
	if (!(finalb = finalbase(finalsize)))
		return (-1);//osvobodit pamyat v struct
	solve(begin, finalsize, finalb);
}
