/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:30:01 by sazalee           #+#    #+#             */
/*   Updated: 2019/07/30 12:38:42 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_error(void)
{
	write(1, ERROR, 6);
}

int		main(int ac, char **av)
{
	t_tetris	*begin;
	char		**base;

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
}
