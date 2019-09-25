/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:30:01 by sazalee           #+#    #+#             */
/*   Updated: 2019/09/25 17:42:37 by sazalee          ###   ########.fr       */
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
		free(base[flag]);
		flag++;
	}
	free(base);
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

int		read_check_checker(int c, char *v, char **b, t_tetris **beg)
{
	if ((c != 2) || ((b = ft_read(v)) == NULL) || (g_tetrinumber > 26))
	{
		ft_error();
		return (0);
	}
	if (!(check(b)))
	{
		ft_error();
		ft_freetime(b, g_tetrinumber);
		return (0);
	}
	*beg = addtetri(b);
	ft_freetime(b, g_tetrinumber + 1);
	return (1);
}

int		main(int ac, char **av)
{
	t_tetris	*begin;
	char		**base;
	char		**finalb;
	int			finalsize;

	begin = NULL;
	base = NULL;
	if (!(read_check_checker(ac, av[1], base, &begin)))
		return (-1);
	finalsize = ressize();
	finalb = finalbase(finalsize);
	solve(begin, finalsize, finalb);
	/*free_lst(begin);*/
}
